#pragma once
#include <QString>
#include <QDate>
#include <QSharedDataPointer>

namespace preventiva::core {

class MachineData : public QSharedData {
public:
    QString id;
    QString clientId;
    QDate   lastAnyMaintenanceDate;
    int     lastSimpleAtHours = 0;   // horímetro quando fez a última de 250h
    int     lastCompleteAtHours = 0; // horímetro quando fez a última de 750h
    int     lastHorimeter = 0;       // última leitura conhecida
};

class Machine {
public:
    Machine();
    Machine(const QString& id, const QString& clientId);

    QString id() const;
    QString clientId() const;
    QDate   lastAnyMaintenanceDate() const;
    int     lastSimpleAtHours() const;
    int     lastCompleteAtHours() const;
    int     lastHorimeter() const;

    void setClientId(const QString& v);
    void setLastAnyMaintenanceDate(const QDate& d);
    void setLastSimpleAtHours(int v);
    void setLastCompleteAtHours(int v);
    void setLastHorimeter(int v);

private:
    QSharedDataPointer<MachineData> d;
};

} // namespace preventiva::core
