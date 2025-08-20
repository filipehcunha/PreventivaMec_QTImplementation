#pragma once
#include "../../app/IMaintenanceOrderRepository.h"
#include <QVector>

namespace preventiva::infra {

class InMemoryMaintenanceOrderRepository : public preventiva::app::IMaintenanceOrderRepository {
public:
    bool save(const preventiva::core::MaintenanceOrder& o) override;
    QVector<preventiva::core::MaintenanceOrder> byMachine(const QString& machineId) const override;
    QVector<preventiva::core::MaintenanceOrder> all() const override;
private:
    QVector<preventiva::core::MaintenanceOrder> m_orders;
};

} // namespace
