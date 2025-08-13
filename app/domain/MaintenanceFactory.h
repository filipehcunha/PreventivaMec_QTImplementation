/**
 * @file MaintenanceFactory.h
 * @brief Padrão Factory para instanciar estratégias a partir de uma policy.
 */
#pragma once
#include "SchedulingStrategy.h"
#include "preventiva/Types.h"
#include <memory>

namespace Domain {

class MaintenanceFactory {
public:
    static std::unique_ptr<ISchedulingStrategy> make(Preventiva::SchedulePolicy policy) {
        using Preventiva::SchedulePolicy;
        switch (policy) {
            case SchedulePolicy::TimeBased: return std::make_unique<TimeBasedStrategy>(6);   // 6 meses
            case SchedulePolicy::UsageBased: return std::make_unique<UsageBasedStrategy>(250); // 250h
        }
        return std::make_unique<TimeBasedStrategy>(6);
    }
};

} // namespace Domain
