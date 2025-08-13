#pragma once
#include "preventiva/IAlertService.h"
#include "ConsoleLogger.h"
class QtEmailAdapter : public Preventiva::IAlertService {
public: void notifyClient(const QString& machineId, const QString& message) override;
private: ConsoleLogger logger;
};
