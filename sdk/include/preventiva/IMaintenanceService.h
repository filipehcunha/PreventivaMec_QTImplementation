#pragma once
#include <QtPlugin>
#include <QString>
#include <QVector>
#include "Types.h"

namespace Preventiva {

class IMachineRepository; class IAlertService;

class IMaintenanceService {
public:
    virtual ~IMaintenanceService() = default;
    virtual void setDependencies(IMachineRepository* repo, IAlertService* alerts) = 0;
    virtual MaintenanceOrder schedule(const QString& machineId, SchedulePolicy policy, const QString& notes) = 0;
    virtual QVector<MaintenanceOrder> history(const QString& machineId) const = 0;
};

} // namespace Preventiva

#define Preventiva_IMaintenanceService_iid "br.sejaefi.preventiva.IMaintenanceService/1.0"
Q_DECLARE_INTERFACE(Preventiva::IMaintenanceService, Preventiva_IMaintenanceService_iid)
