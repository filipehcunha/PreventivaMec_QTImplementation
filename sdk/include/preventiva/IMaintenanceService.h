/**
 * @file IMaintenanceService.h
 * @brief Interface para serviços de manutenção preventiva (carregados via plugin DLL).
 */
#pragma once
#include <QtPlugin>
#include <QString>
#include <QVector>
#include "Types.h"

namespace Preventiva {

class IMachineRepository;
class IAlertService;

class IMaintenanceService
{
public:
    virtual ~IMaintenanceService() = default;

    /// Configuração de dependências (DI) fornecidas pela aplicação
    virtual void setDependencies(IMachineRepository* repo, IAlertService* alerts) = 0;

    /// Planeja e registra uma OS de manutenção para a máquina informada.
    virtual MaintenanceOrder schedule(const QString& machineId,
                                      SchedulePolicy policy,
                                      const QString& notes) = 0;

    /// Lista histórico de OS para uma máquina.
    virtual QVector<MaintenanceOrder> history(const QString& machineId) const = 0;
};

} // namespace Preventiva

#define Preventiva_IMaintenanceService_iid "br.sejaefi.preventiva.IMaintenanceService/1.0"
Q_DECLARE_INTERFACE(Preventiva::IMaintenanceService, Preventiva_IMaintenanceService_iid)
