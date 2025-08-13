#include <QtTest>
#include <QTemporaryDir>
#include <QFile>
#include <QTextStream>
#include "infrastructure/JsonMachineRepository.h"
#include "infrastructure/ConsoleLogger.h"
#include "infrastructure/QtEmailAdapter.h"

static QStringList g_logs;
static QtMessageHandler g_prev = nullptr;
static void cap(QtMsgType, const QMessageLogContext&, const QString& msg){ g_logs << msg; }

class UnitInfraTests : public QObject {
    Q_OBJECT
private slots:
    void initTestCase(){ g_prev = qInstallMessageHandler(cap); }
    void cleanupTestCase(){ qInstallMessageHandler(g_prev); }

    void test_json_repository_rw() {
        QTemporaryDir dir;
        QVERIFY(dir.isValid());
        QString path = dir.path() + "/machines.json";

        // Cria arquivo com 1 máquina
        QFile f(path); QVERIFY(f.open(QIODevice::WriteOnly|QIODevice::Truncate));
        f.write(R"([{"id":"T1","model":"Teste","hours":10}])"); f.close();

        JsonMachineRepository repo(path);
        auto list = repo.list();
        QCOMPARE(list.size(), 1);
        QCOMPARE(list[0].id, QString("T1"));

        // Salva nova máquina e lê de volta
        Preventiva::Machine m2{"T2","Modelo X", 200};
        repo.save(m2);
        auto list2 = repo.list();
        QVERIFY(list2.size() >= 2);
        bool found=false; for(const auto& m: list2) if(m.id=="T2") found=true;
        QVERIFY(found);
    }

    void test_email_adapter_logs() {
        g_logs.clear();
        QtEmailAdapter adapter;
        adapter.notifyClient("M1", "Mensagem de teste");
        bool ok = std::any_of(g_logs.begin(), g_logs.end(), [](const QString& s){
            return s.contains("[E-mail ao cliente]") && s.contains("Mensagem de teste");
        });
        QVERIFY2(ok, "Deveria ter log indicando notificação ao cliente");
    }
};

QTEST_MAIN(UnitInfraTests)
#include "UnitInfraTests.moc"
