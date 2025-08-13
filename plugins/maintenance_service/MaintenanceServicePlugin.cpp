#include "MaintenanceServicePlugin.h"
#include <QDebug>

using namespace Preventiva;

void MaintenanceServicePlugin::setDependencies(IMachineRepository* repo, IAlertService* alerts)
{
    m_repo = repo;
    m_alerts = alerts;
}

MaintenanceOrder MaintenanceServicePlugin::schedule(const QString& machineId,
                                                    SchedulePolicy policy,
                                                    const QString& notes)
{
    auto m = m_repo->get(machineId); // valida existência

    MaintenanceOrder order;
    order.id = QString::number(qHash(machineId + QString::number(QDateTime::currentMSecsSinceEpoch())));
    order.machineId = m.id;
    order.policy = policy;
    order.scheduledAt = QDateTime::currentDateTime();
    order.notes = notes;

    m_orders[machineId].push_back(order);

    if (m_alerts) {
        m_alerts->notifyClient(machineId, QString("OS %1 agendada (%2).").arg(order.id).arg(policy == SchedulePolicy::TimeBased ? "Tempo" : "Horas"));
    }

    return order;
}

QVector<MaintenanceOrder> MaintenanceServicePlugin::history(const QString& machineId) const
{
    return m_orders.value(machineId);
}
