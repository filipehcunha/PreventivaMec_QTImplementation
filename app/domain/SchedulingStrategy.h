#pragma once
#include <QDateTime>
#include "preventiva/Types.h"

namespace Domain {
class ISchedulingStrategy { public: virtual ~ISchedulingStrategy()=default; virtual QDateTime nextDate(const QDateTime& from) const = 0; };
class TimeBasedStrategy : public ISchedulingStrategy { int m_months; public: explicit TimeBasedStrategy(int months):m_months(months){} QDateTime nextDate(const QDateTime& from) const override { return from.addMonths(m_months);} };
class UsageBasedStrategy : public ISchedulingStrategy { int m_hours; public: explicit UsageBasedStrategy(int hours):m_hours(hours){} QDateTime nextDate(const QDateTime& from) const override { return from.addDays(m_hours/8);} };
}
