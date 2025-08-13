#pragma once
#include <QString>
class ILogger{ public: virtual ~ILogger()=default; virtual void info(const QString&)=0; virtual void error(const QString&)=0; };
