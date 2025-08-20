#pragma once
#include <QObject>
#include <memory>
#include "IAlertDispatcher.h"
#include "../core/MaintenanceOrder.h"

namespace preventiva::app {

class AlertService : public QObject {
    Q_OBJECT
public:
    explicit AlertService(std::shared_ptr<IAlertDispatcher> dispatcher, QObject* parent = nullptr);

public slots:
    void onMaintenanceScheduled(const preventiva::core::MaintenanceOrder& order);

private:
    std::shared_ptr<IAlertDispatcher> m_dispatcher;
};

} // namespace
