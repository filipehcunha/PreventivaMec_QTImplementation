#pragma once
#include "preventiva/IAlertService.h"
#include "ConsoleLogger.h"

/**
 * @brief Adapter que, nesta demo, apenas loga; numa implementação real, enviaria e-mail.
 */
class QtEmailAdapter : public Preventiva::IAlertService {
public:
    void notifyClient(const QString& machineId, const QString& message) override;
private:
    ConsoleLogger logger;
};
