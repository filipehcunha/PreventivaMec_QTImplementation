#pragma once
#include <QObject>
#include <QVector>
#include <QDateTime>
#include <QHash>
#include "preventiva/IMaintenanceService.h"
#include "preventiva/IMachineRepository.h"
#include "preventiva/IAlertService.h"

class MaintenanceServicePlugin : public QObject, public Preventiva::IMaintenanceService
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID Preventiva_IMaintenanceService_iid FILE "plugin.json")
    Q_INTERFACES(Preventiva::IMaintenanceService)
public:
    void setDependencies(Preventiva::IMachineRepository* repo, Preventiva::IAlertService* alerts) override;
    Preventiva::MaintenanceOrder schedule(const QString& machineId, Preventiva::SchedulePolicy policy, const QString& notes) override;
    QVector<Preventiva::MaintenanceOrder> history(const QString& machineId) const override;
private:
    Preventiva::IMachineRepository* m_repo = nullptr;
    Preventiva::IAlertService* m_alerts = nullptr;
    mutable QHash<QString, QVector<Preventiva::MaintenanceOrder>> m_orders;
};
