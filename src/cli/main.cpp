#include <QCoreApplication>
#include <QTextStream>
#include "../app/UseCases.h"
#include "../infrastructure/memory/InMemoryMachineRepository.h"
#include "../infrastructure/memory/InMemoryMaintenanceOrderRepository.h"
#include "../infrastructure/email/FakeEmailDispatcher.h"

using namespace preventiva;

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QTextStream out(stdout);

    auto machines = std::make_shared<infra::InMemoryMachineRepository>();
    auto orders = std::make_shared<infra::InMemoryMaintenanceOrderRepository>();
    auto dispatcher = std::make_shared<infra::FakeEmailDispatcher>();
    auto wiring = app::wireApp(machines, orders, dispatcher);

    // Seed: cria máquina e registra leituras
    core::Machine m("M001", "C001");
    m.setLastAnyMaintenanceDate(QDate::currentDate().addMonths(-7));
    m.setLastSimpleAtHours(1000);
    m.setLastCompleteAtHours(500);
    m.setLastHorimeter(1100);
    machines->save(m);

    wiring.scheduler->recordReading("M001", 1760, QDate::currentDate());

    out << "Ordens criadas: " << orders->all().size() << Qt::endl;
    for (const auto& o : orders->all()) {
        out << " - " << o.machineId << " | " << core::toString(o.kind) << " | " << o.reason << " | " << o.dueDate.toString(Qt::ISODate) << Qt::endl;
    }
    out << "Alertas enviados: " << dispatcher->sent().size() << Qt::endl;
    for (const auto& a : dispatcher->sent()) {
        out << " * Alerta: " << a.subject << " :: " << a.body << Qt::endl;
    }

    return 0;
}
