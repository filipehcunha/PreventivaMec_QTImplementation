#pragma once
#include "ILogger.h"

class ConsoleLogger : public ILogger {
public:
    void info(const QString& msg) override;
    void error(const QString& msg) override;
};
