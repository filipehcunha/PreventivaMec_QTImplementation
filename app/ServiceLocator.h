/**
 * @file ServiceLocator.h
 * @brief Fachada/Service Locator para obter serviços (plugin + repositórios).
 */
#pragma once
#include <QString>
#include <QDir>
#include <QPluginLoader>
#include <QScopedPointer>
#include "preventiva/IMaintenanceService.h"
#include "preventiva/IMachineRepository.h"
#include "preventiva/IAlertService.h"

class ServiceLocator {
public:
    ServiceLocator();
    ~ServiceLocator();

    Preventiva::IMaintenanceService* maintenance();
    Preventiva::IMachineRepository* machineRepository();
    Preventiva::IAlertService* alertService();

private:
    QObject* loadPlugin(const QString& iid);

    QScopedPointer<Preventiva::IMachineRepository> m_repo;
    QScopedPointer<Preventiva::IAlertService> m_alerts;
    QScopedPointer<QObject> m_pluginObj;
    Preventiva::IMaintenanceService* m_maint = nullptr;
};
