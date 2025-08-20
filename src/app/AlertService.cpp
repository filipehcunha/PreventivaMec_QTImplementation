#include "AlertService.h"
#include <QString>

using namespace preventiva::app;
using namespace preventiva::core;

AlertService::AlertService(std::shared_ptr<IAlertDispatcher> dispatcher, QObject* parent)
    : QObject(parent), m_dispatcher(std::move(dispatcher)) {}

void AlertService::onMaintenanceScheduled(const MaintenanceOrder& order) {
    Alert a;
    a.machineId = order.machineId;
    a.subject = QString("Manutenção %1 programada").arg(toString(order.kind));
    a.body = QString("Motivo: %1 | Vencimento: %2").arg(order.reason, order.dueDate.toString(Qt::ISODate));
    m_dispatcher->dispatch(a);
}
