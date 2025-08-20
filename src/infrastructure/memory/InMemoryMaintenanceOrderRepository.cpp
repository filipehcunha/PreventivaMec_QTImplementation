#include "InMemoryMaintenanceOrderRepository.h"

using namespace preventiva::infra;
using namespace preventiva::core;

bool InMemoryMaintenanceOrderRepository::save(const MaintenanceOrder& o) {
    m_orders.push_back(o);
    return true;
}

QVector<MaintenanceOrder> InMemoryMaintenanceOrderRepository::byMachine(const QString& machineId) const {
    QVector<MaintenanceOrder> out;
    for (const auto& o : m_orders) if (o.machineId == machineId) out.push_back(o);
    return out;
}

QVector<MaintenanceOrder> InMemoryMaintenanceOrderRepository::all() const {
    return m_orders;
}
