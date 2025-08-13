#include "ServiceLocator.h"
#include "infrastructure/JsonMachineRepository.h"
#include "infrastructure/QtEmailAdapter.h"
#include <QCoreApplication>
#include <QDebug>
using namespace Preventiva;

ServiceLocator::ServiceLocator() {}
ServiceLocator::~ServiceLocator() {}

QObject* ServiceLocator::loadPlugin(const QString& iid){
    QDir pluginsDir(QCoreApplication::applicationDirPath() + "/../plugins");
    for (const auto& fileName : pluginsDir.entryList(QDir::Files)) {
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
        if (QObject* plugin = loader.instance()) {
            if (plugin->qt_metacast(iid.toUtf8().constData())) return plugin;
        }
    }
    return nullptr;
}

IMaintenanceService* ServiceLocator::maintenance(){
    if (!m_maint) {
        if (!m_pluginObj) m_pluginObj.reset(loadPlugin(Preventiva_IMaintenanceService_iid));
        if (m_pluginObj) {
            m_maint = qobject_cast<IMaintenanceService*>(m_pluginObj.data());
            if (m_maint) {
                if (!m_repo) m_repo.reset(new JsonMachineRepository("machines.json"));
                if (!m_alerts) m_alerts.reset(new QtEmailAdapter);
                m_maint->setDependencies(m_repo.data(), m_alerts.data());
            }
        }
    }
    return m_maint;
}

IMachineRepository* ServiceLocator::machineRepository(){ if(!m_repo) m_repo.reset(new JsonMachineRepository("machines.json")); return m_repo.data(); }
IAlertService* ServiceLocator::alertService(){ if(!m_alerts) m_alerts.reset(new QtEmailAdapter); return m_alerts.data(); }
