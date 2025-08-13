#include <QtTest>
#include <QApplication>
#include <QTableView>
#include <QPushButton>
#include <QStandardItemModel>
#include "MainWindow.h"

static QStringList g_captured;
static QtMessageHandler g_prevHandler = nullptr;
static void capture(QtMsgType, const QMessageLogContext&, const QString &msg) { g_captured << msg; }

class FunctionalGuiTests : public QObject {
    Q_OBJECT
private slots:
    void initTestCase(){ g_prevHandler = qInstallMessageHandler(capture); }
    void cleanupTestCase(){ qInstallMessageHandler(g_prevHandler); }

    void test_list_shows_rows_and_schedule_flow() {
        g_captured.clear();
        MainWindow w; w.show(); QVERIFY(QTest::qWaitForWindowExposed(&w));
        auto tv = w.findChild<QTableView*>("tableView"); QVERIFY(tv);
        auto btn = w.findChild<QPushButton*>("btnSchedule"); QVERIFY(btn);
        auto model = qobject_cast<QStandardItemModel*>(tv->model()); QVERIFY(model);
        QVERIFY(model->rowCount() >= 1);

        // Seleciona primeira linha e agenda
        QModelIndex idx = model->index(0,0); QVERIFY(idx.isValid());
        tv->selectionModel()->select(idx, QItemSelectionModel::Select | QItemSelectionModel::Rows);
        tv->setCurrentIndex(idx);
        QTest::mouseClick(btn, Qt::LeftButton);
        QTRY_VERIFY_WITH_TIMEOUT(!g_captured.isEmpty(), 1000);
        bool hasEmail = std::any_of(g_captured.begin(), g_captured.end(), [](const QString& s){
            return s.contains("[E-mail ao cliente]") && s.contains("agendada");
        });
        QVERIFY2(hasEmail, "Fluxo funcional deveria emitir notificação (log)");
    }
};

QTEST_MAIN(FunctionalGuiTests)
#include "FunctionalGuiTests.moc"
