#pragma once
#include "SchedulingStrategy.h"
#include "preventiva/Types.h"
#include <memory>

namespace Domain {
class MaintenanceFactory {
public:
    static std::unique_ptr<ISchedulingStrategy> make(Preventiva::SchedulePolicy policy){
        using Preventiva::SchedulePolicy;
        switch(policy){
            case SchedulePolicy::TimeBased: return std::make_unique<TimeBasedStrategy>(6);
            case SchedulePolicy::UsageBased: return std::make_unique<UsageBasedStrategy>(250);
        }
        return std::make_unique<TimeBasedStrategy>(6);
    }
};
}
