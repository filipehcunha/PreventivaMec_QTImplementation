#include "Scheduler.h"
#include <QUuid>

using namespace preventiva::app;
using namespace preventiva::core;

Scheduler::Scheduler(std::shared_ptr<IMachineRepository> machines,
                     std::shared_ptr<IMaintenanceOrderRepository> orders,
                     std::shared_ptr<MaintenancePolicy> policy,
                     QObject* parent)
    : QObject(parent), m_machines(std::move(machines)), m_orders(std::move(orders)), m_policy(std::move(policy)) {}

bool Scheduler::recordReading(const QString& machineId, int newHorimeter, const QDate& readingDate) {
    auto om = m_machines->get(machineId);
    if (!om) return false;
    auto m = *om;
    m.setLastHorimeter(newHorimeter);

    // Avaliar políticas
    if (auto eval = m_policy->evaluate(m, newHorimeter, readingDate)) {
        MaintenanceOrder order;
        order.id = QUuid::createUuid().toString(QUuid::WithoutBraces);
        order.machineId = machineId;
        order.kind = *(eval->kind);
        order.dueDate = eval->dueDate;
        order.reason = eval->reason;
        m_orders->save(order);

        // Atualizar marcadores conforme o tipo
        if (order.kind == MaintenanceKind::Simple250) {
            m.setLastSimpleAtHours(newHorimeter);
        } else if (order.kind == MaintenanceKind::Complete750) {
            m.setLastCompleteAtHours(newHorimeter);
        }
        m.setLastAnyMaintenanceDate(eval->dueDate);
        m_machines->save(m);

        emit maintenanceScheduled(order);
    } else {
        // Apenas salvar a nova leitura
        m_machines->save(m);
    }
    return true;
}
