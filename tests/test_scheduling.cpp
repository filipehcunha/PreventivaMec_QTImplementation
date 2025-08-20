#include <QtTest>
#include "../src/app/UseCases.h"
#include "../src/infrastructure/memory/InMemoryMachineRepository.h"
#include "../src/infrastructure/memory/InMemoryMaintenanceOrderRepository.h"
#include "../src/infrastructure/email/FakeEmailDispatcher.h"

using namespace preventiva;

class TestScheduling : public QObject
{
    Q_OBJECT
private slots:
    void due_simple250();
    void due_complete750_first();
    void due_semiannual();
};

void TestScheduling::due_simple250()
{
    auto machines = std::make_shared<infra::InMemoryMachineRepository>();
    auto orders = std::make_shared<infra::InMemoryMaintenanceOrderRepository>();
    auto dispatcher = std::make_shared<infra::FakeEmailDispatcher>();
    auto wiring = app::wireApp(machines, orders, dispatcher);

    core::Machine m("M1", "C1");
    m.setLastAnyMaintenanceDate(QDate::currentDate().addMonths(-1));
    m.setLastSimpleAtHours(1000);
    m.setLastCompleteAtHours(900); // <-- 1255 - 900 = 355 (< 750) => 750h NÃO vence
    m.setLastHorimeter(1100);
    machines->save(m);

    QVERIFY(wiring.scheduler->recordReading("M1", 1255, QDate::currentDate()));
    QCOMPARE(orders->all().size(), 1);
    QCOMPARE(dispatcher->sent().size(), 1);
    QCOMPARE(core::toString(orders->all().first().kind), QString("Simple250")); // 1255 - 1000 = 255 (>= 250)
}

void TestScheduling::due_complete750_first()
{
    auto machines = std::make_shared<infra::InMemoryMachineRepository>();
    auto orders = std::make_shared<infra::InMemoryMaintenanceOrderRepository>();
    auto dispatcher = std::make_shared<infra::FakeEmailDispatcher>();
    auto wiring = app::wireApp(machines, orders, dispatcher);

    core::Machine m("M2", "C1");
    m.setLastAnyMaintenanceDate(QDate::currentDate().addMonths(-1));
    m.setLastSimpleAtHours(0);
    m.setLastCompleteAtHours(0);
    m.setLastHorimeter(0);
    machines->save(m);

    QVERIFY(wiring.scheduler->recordReading("M2", 751, QDate::currentDate()));
    QCOMPARE(orders->all().size(), 1);
    QCOMPARE(core::toString(orders->all().first().kind), QString("Complete750"));
}

void TestScheduling::due_semiannual()
{
    auto machines = std::make_shared<infra::InMemoryMachineRepository>();
    auto orders = std::make_shared<infra::InMemoryMaintenanceOrderRepository>();
    auto dispatcher = std::make_shared<infra::FakeEmailDispatcher>();
    auto wiring = app::wireApp(machines, orders, dispatcher);

    core::Machine m("M3", "C1");
    m.setLastAnyMaintenanceDate(QDate::currentDate().addMonths(-7));
    m.setLastSimpleAtHours(1000);
    m.setLastCompleteAtHours(1000);
    m.setLastHorimeter(1000);
    machines->save(m);

    QVERIFY(wiring.scheduler->recordReading("M3", 1001, QDate::currentDate()));
    QCOMPARE(orders->all().size(), 1);
    QCOMPARE(core::toString(orders->all().first().kind), QString("Semiannual"));
}

#include "test_scheduling.moc"