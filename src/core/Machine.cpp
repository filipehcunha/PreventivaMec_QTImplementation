#include "Machine.h"

using namespace preventiva::core;

Machine::Machine() : d(new MachineData) {}
Machine::Machine(const QString& id, const QString& clientId) : d(new MachineData) {
    d->id = id;
    d->clientId = clientId;
    d->lastAnyMaintenanceDate = QDate::currentDate();
}

QString Machine::id() const { return d->id; }
QString Machine::clientId() const { return d->clientId; }
QDate   Machine::lastAnyMaintenanceDate() const { return d->lastAnyMaintenanceDate; }
int     Machine::lastSimpleAtHours() const { return d->lastSimpleAtHours; }
int     Machine::lastCompleteAtHours() const { return d->lastCompleteAtHours; }
int     Machine::lastHorimeter() const { return d->lastHorimeter; }

void Machine::setClientId(const QString& v) { d->clientId = v; }
void Machine::setLastAnyMaintenanceDate(const QDate& v) { d->lastAnyMaintenanceDate = v; }
void Machine::setLastSimpleAtHours(int v) { d->lastSimpleAtHours = v; }
void Machine::setLastCompleteAtHours(int v) { d->lastCompleteAtHours = v; }
void Machine::setLastHorimeter(int v) { d->lastHorimeter = v; }
