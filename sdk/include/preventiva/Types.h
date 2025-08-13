/**
 * @file Types.h
 * @brief Tipos básicos compartilhados entre App e Plugins.
 */
#pragma once
#include <QString>
#include <QDateTime>

namespace Preventiva {

struct Machine {
    QString id;
    QString model;
    int hours = 0;
};

enum class SchedulePolicy {
    TimeBased,   ///< Por tempo (ex.: 6 meses)
    UsageBased   ///< Por horas (ex.: 250/750h)
};

struct MaintenanceOrder {
    QString id;
    QString machineId;
    SchedulePolicy policy;
    QDateTime scheduledAt;
    QString notes;
};

} // namespace Preventiva
