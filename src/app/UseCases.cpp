#include "UseCases.h"
#include <memory>

namespace preventiva::app {

AppWiring wireApp(std::shared_ptr<IMachineRepository> machines,
                  std::shared_ptr<IMaintenanceOrderRepository> orders,
                  std::shared_ptr<IAlertDispatcher> dispatcher) {
    AppWiring w;
    w.machines = std::move(machines);
    w.orders = std::move(orders);
    w.dispatcher = std::move(dispatcher);

    auto composite = std::make_shared<PolicyComposite>();
    composite->add(std::make_shared<HoursPolicy>(750, preventiva::core::MaintenanceKind::Complete750));
    composite->add(std::make_shared<HoursPolicy>(250, preventiva::core::MaintenanceKind::Simple250));
    composite->add(std::make_shared<SemiannualPolicy>());
    w.policy = composite;

    w.scheduler = std::make_shared<Scheduler>(w.machines, w.orders, w.policy);
    w.alertService = std::make_shared<AlertService>(w.dispatcher);
    QObject::connect(w.scheduler.get(), &Scheduler::maintenanceScheduled, w.alertService.get(), &AlertService::onMaintenanceScheduled);
    return w;
}

} // namespace preventiva::app
