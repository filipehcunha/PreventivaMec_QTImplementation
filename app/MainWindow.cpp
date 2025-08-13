#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "domain/MaintenanceFactory.h"
#include <QMessageBox>

using namespace Preventiva;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_model);
    m_model.setHorizontalHeaderLabels({"ID", "Modelo", "Horas"});
    refreshMachines();

    connect(ui->btnSchedule, &QPushButton::clicked, this, &MainWindow::on_btnSchedule_clicked);
}

MainWindow::~MainWindow(){ delete ui; }

void MainWindow::refreshMachines()
{
    m_model.removeRows(0, m_model.rowCount());
    auto repo = services.machineRepository();
    for (const auto& m : repo->list()) {
        QList<QStandardItem*> row;
        row << new QStandardItem(m.id);
        row << new QStandardItem(m.model);
        row << new QStandardItem(QString::number(m.hours));
        m_model.appendRow(row);
    }
}

void MainWindow::on_btnSchedule_clicked()
{
    auto maint = services.maintenance();
    if (!maint) {
        QMessageBox::critical(this, "Plugin não encontrado", "Nenhum plugin de manutenção foi carregado.");
        return;
    }

    auto sel = ui->tableView->currentIndex();
    if (!sel.isValid()) {
        QMessageBox::warning(this, "Selecione", "Selecione uma máquina para agendar.");
        return;
    }
    const auto machineId = m_model.item(sel.row(), 0)->text();

    // Escolhe uma policy simples: alterna entre tempo e horas para demo
    static bool toggle=false; toggle = !toggle;
    const auto policy = toggle ? SchedulePolicy::TimeBased : SchedulePolicy::UsageBased;

    // Uso do Factory + Strategy (internos ao app) apenas para exibição/explicação
    auto strategy = Domain::MaintenanceFactory::make(policy);
    const auto nextDate = strategy->nextDate(QDateTime::currentDateTime());

    auto order = maint->schedule(machineId, policy, QString("Próxima: %1").arg(nextDate.toString(Qt::ISODate)));
    QMessageBox::information(this, "OS criada",
        QString("OS %1 criada para Máquina %2\nPolicy: %3\n%4")
        .arg(order.id, order.machineId, policy==SchedulePolicy::TimeBased? "Tempo" : "Horas", order.notes));
}
