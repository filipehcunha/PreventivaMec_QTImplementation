#pragma once
#include "ILogger.h"
class ConsoleLogger : public ILogger { public: void info(const QString&) override; void error(const QString&) override; };
