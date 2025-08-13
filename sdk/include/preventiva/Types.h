#pragma once
#include <QString>
#include <QDateTime>

namespace Preventiva {

struct Machine { QString id; QString model; int hours = 0; };

enum class SchedulePolicy { TimeBased, UsageBased };

struct MaintenanceOrder {
    QString id;
    QString machineId;
    SchedulePolicy policy;
    QDateTime scheduledAt;
    QString notes;
};

} // namespace Preventiva
