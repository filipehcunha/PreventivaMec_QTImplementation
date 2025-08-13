/**
 * @file SchedulingStrategy.h
 * @brief Padrão Strategy para cálculo de próxima manutenção.
 */
#pragma once
#include <QDateTime>
#include "preventiva/Types.h"

namespace Domain {

class ISchedulingStrategy {
public:
    virtual ~ISchedulingStrategy() = default;
    virtual QDateTime nextDate(const QDateTime& from) const = 0;
};

/// Por tempo (ex.: +6 meses)
class TimeBasedStrategy : public ISchedulingStrategy {
public:
    explicit TimeBasedStrategy(int months) : m_months(months) {}
    QDateTime nextDate(const QDateTime& from) const override { return from.addMonths(m_months); }
private:
    int m_months;
};

/// Por uso (ex.: +250h / +750h) — aqui simulamos dias aproximados.
class UsageBasedStrategy : public ISchedulingStrategy {
public:
    explicit UsageBasedStrategy(int hours) : m_hours(hours) {}
    QDateTime nextDate(const QDateTime& from) const override {
        int approxDays = m_hours / 8; // 8h/dia (simplificação)
        return from.addDays(approxDays);
    }
private:
    int m_hours;
};

} // namespace Domain
