#pragma once
#include <QVector>
#include "../core/MaintenanceOrder.h"

namespace preventiva::app {

class IMaintenanceOrderRepository {
public:
    virtual ~IMaintenanceOrderRepository() = default;
    virtual bool save(const preventiva::core::MaintenanceOrder& o) = 0;
    virtual QVector<preventiva::core::MaintenanceOrder> byMachine(const QString& machineId) const = 0;
    virtual QVector<preventiva::core::MaintenanceOrder> all() const = 0;
};

} // namespace
