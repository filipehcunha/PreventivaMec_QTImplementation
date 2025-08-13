#include "ConsoleLogger.h"
#include <QDebug>
void ConsoleLogger::info(const QString& msg){ qInfo().noquote() << "[INFO]" << msg; }
void ConsoleLogger::error(const QString& msg){ qCritical().noquote() << "[ERROR]" << msg; }
