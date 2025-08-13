#include <QtTest>
#include <QApplication>
#include <QTableView>
#include <QPushButton>
#include <QStandardItemModel>
#include "MainWindow.h"

static QStringList g_captured;
static QtMessageHandler g_prevHandler = nullptr;
static void captureHandler(QtMsgType, const QMessageLogContext&, const QString &msg) { g_captured << msg; }

class GuiTests : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase() { g_prevHandler = qInstallMessageHandler(captureHandler); }
    void cleanupTestCase() { qInstallMessageHandler(g_prevHandler); }

    void test_01_initial_table_has_rows() {
        MainWindow w; w.show(); QVERIFY(QTest::qWaitForWindowExposed(&w));
        auto tv = w.findChild<QTableView*>("tableView"); QVERIFY(tv);
        auto model = qobject_cast<QStandardItemModel*>(tv->model()); QVERIFY(model);
        QVERIFY2(model->rowCount() >= 1, "A tabela deve ter ao menos 1 linha");
    }

    void test_02_click_without_selection_should_not_send_email() {
        g_captured.clear();
        MainWindow w; w.show(); QVERIFY(QTest::qWaitForWindowExposed(&w));
        auto tv = w.findChild<QTableView*>("tableView");
        auto btn = w.findChild<QPushButton*>("btnSchedule");
        QVERIFY(tv && btn);
        tv->clearSelection();
        QTest::mouseClick(btn, Qt::LeftButton);
        QTest::qWait(100);
        bool hasEmailLog = std::any_of(g_captured.begin(), g_captured.end(), [](const QString& s){
            return s.contains("[E-mail ao cliente]");
        });
        QVERIFY2(!hasEmailLog, "Não deveria enviar e-mail quando não há seleção");
    }

    void test_03_click_with_selection_should_trigger_email_log() {
        g_captured.clear();
        MainWindow w; w.show(); QVERIFY(QTest::qWaitForWindowExposed(&w));
        auto tv = w.findChild<QTableView*>("tableView");
        auto btn = w.findChild<QPushButton*>("btnSchedule");
        QVERIFY(tv && btn);
        QModelIndex idx = tv->model()->index(0,0); QVERIFY(idx.isValid());
        tv->selectionModel()->select(idx, QItemSelectionModel::Select | QItemSelectionModel::Rows);
        tv->setCurrentIndex(idx);
        QTest::mouseClick(btn, Qt::LeftButton);
        QTRY_VERIFY_WITH_TIMEOUT(!g_captured.isEmpty(), 1000);
        bool hasEmailLog = std::any_of(g_captured.begin(), g_captured.end(), [](const QString& s){
            return s.contains("[E-mail ao cliente]") && s.contains("agendada");
        });
        QVERIFY2(hasEmailLog, "Deveria haver log de e-mail simulando notificação ao cliente");
    }
};

QTEST_MAIN(GuiTests)
#include "TestMainWindow.moc"
