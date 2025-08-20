#pragma once
#include <QObject>
#include <memory>
#include "IMachineRepository.h"
#include "IMaintenanceOrderRepository.h"
#include "policies/MaintenancePolicy.h"
#include "../core/MaintenanceOrder.h"

namespace preventiva::app {

class Scheduler : public QObject {
    Q_OBJECT
public:
    Scheduler(std::shared_ptr<IMachineRepository> machines,
              std::shared_ptr<IMaintenanceOrderRepository> orders,
              std::shared_ptr<MaintenancePolicy> policy,
              QObject* parent = nullptr);

    // Registra leitura do horímetro e avalia disparo de manutenção
    bool recordReading(const QString& machineId, int newHorimeter, const QDate& readingDate);

signals:
    void maintenanceScheduled(const preventiva::core::MaintenanceOrder& order);

private:
    std::shared_ptr<IMachineRepository> m_machines;
    std::shared_ptr<IMaintenanceOrderRepository> m_orders;
    std::shared_ptr<MaintenancePolicy> m_policy;
};

} // namespace
