#include "QtEmailAdapter.h"
void QtEmailAdapter::notifyClient(const QString& machineId, const QString& message){
    logger.info(QString("[E-mail ao cliente][máquina %1] %2").arg(machineId, message));
}
