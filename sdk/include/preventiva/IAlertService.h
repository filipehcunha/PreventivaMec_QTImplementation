#pragma once
#include <QString>
namespace Preventiva {
class IAlertService {
public:
    virtual ~IAlertService() = default;
    virtual void notifyClient(const QString& machineId, const QString& message) = 0;
};
} // namespace Preventiva
