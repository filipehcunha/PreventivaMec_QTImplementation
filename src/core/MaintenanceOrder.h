#pragma once
#include <QString>
#include <QDate>
#include "MaintenanceTypes.h"

namespace preventiva::core {

struct MaintenanceOrder {
    QString id;
    QString machineId;
    MaintenanceKind kind;
    QDate dueDate;
    QString reason; // ">=250h", ">=750h", ">=6m", or combination
};

} // namespace
