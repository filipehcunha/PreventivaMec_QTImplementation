#include "MaintenanceServicePlugin.h"
using namespace Preventiva;
void MaintenanceServicePlugin::setDependencies(IMachineRepository* repo, IAlertService* alerts){ m_repo=repo; m_alerts=alerts; }
MaintenanceOrder MaintenanceServicePlugin::schedule(const QString& machineId, SchedulePolicy policy, const QString& notes){
    auto m = m_repo->get(machineId);
    MaintenanceOrder o; o.id=QString::number(qHash(machineId + QString::number(QDateTime::currentMSecsSinceEpoch())));
    o.machineId=m.id; o.policy=policy; o.scheduledAt=QDateTime::currentDateTime(); o.notes=notes;
    m_orders[machineId].push_back(o);
    if(m_alerts){ m_alerts->notifyClient(machineId, QString("OS %1 agendada (%2).").arg(o.id).arg(policy==SchedulePolicy::TimeBased?"Tempo":"Horas")); }
    return o;
}
QVector<MaintenanceOrder> MaintenanceServicePlugin::history(const QString& machineId) const{ return m_orders.value(machineId); }
