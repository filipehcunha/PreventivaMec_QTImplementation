#pragma once
#include <QString>

class ILogger {
public:
    virtual ~ILogger() = default;
    virtual void info(const QString& msg) = 0;
    virtual void error(const QString& msg) = 0;
};
