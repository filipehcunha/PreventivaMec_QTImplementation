#include <QtTest>
#include "../src/app/UseCases.h"
#include "../src/infrastructure/memory/InMemoryMachineRepository.h"
#include "../src/infrastructure/memory/InMemoryMaintenanceOrderRepository.h"
#include "../src/infrastructure/email/FakeEmailDispatcher.h"

using namespace preventiva;

class TestFunctional : public QObject {
    Q_OBJECT
private slots:
    void end_to_end_policy_priority();
};

// Verifica precedência: 750h > 250h > 6m (primeira política que casa)
void TestFunctional::end_to_end_policy_priority() {
    auto machines   = std::make_shared<infra::InMemoryMachineRepository>();
    auto orders     = std::make_shared<infra::InMemoryMaintenanceOrderRepository>();
    auto dispatcher = std::make_shared<infra::FakeEmailDispatcher>();
    auto wiring     = app::wireApp(machines, orders, dispatcher);

    core::Machine m("MX", "C9");
    m.setLastAnyMaintenanceDate(QDate::currentDate().addMonths(-7));
    m.setLastSimpleAtHours(1000);
    m.setLastCompleteAtHours(1005);
    m.setLastHorimeter(1700);
    machines->save(m);

    QVERIFY(wiring.scheduler->recordReading("MX", 1760, QDate::currentDate()));
    QCOMPARE(orders->all().size(), 1);
    const auto o = orders->all().first();
    QCOMPARE(core::toString(o.kind), QString("Complete750")); // 1760 - 1005 = 755 >= 750

    // Verifica alerta
    QCOMPARE(dispatcher->sent().size(), 1);
    QVERIFY(dispatcher->sent().first().subject.contains("Manutenção"));
}

QTEST_APPLESS_MAIN(TestFunctional)
#include "test_functional.moc"