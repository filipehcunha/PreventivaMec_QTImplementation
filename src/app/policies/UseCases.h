#pragma once
#include <memory>
#include "IMachineRepository.h"
#include "IMaintenanceOrderRepository.h"
#include "IAlertDispatcher.h"
#include "Scheduler.h"
#include "AlertService.h"
#include "policies/PolicyComposite.h"
#include "policies/HoursPolicy.h"
#include "policies/SemiannualPolicy.h"

namespace preventiva::app {

struct AppWiring {
    std::shared_ptr<IMachineRepository> machines;
    std::shared_ptr<IMaintenanceOrderRepository> orders;
    std::shared_ptr<IAlertDispatcher> dispatcher;
    std::shared_ptr<MaintenancePolicy> policy;
    std::shared_ptr<Scheduler> scheduler;
    std::shared_ptr<AlertService> alertService;
};

// Configura o grafo de dependências com políticas 250h, 750h e 6m
AppWiring wireApp(std::shared_ptr<IMachineRepository> machines,
                  std::shared_ptr<IMaintenanceOrderRepository> orders,
                  std::shared_ptr<IAlertDispatcher> dispatcher);

} // namespace
