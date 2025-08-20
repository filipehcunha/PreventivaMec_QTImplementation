#pragma once
#include "MaintenancePolicy.h"

namespace preventiva::app {

class HoursPolicy : public MaintenancePolicy {
public:
    HoursPolicy(int thresholdHours, preventiva::core::MaintenanceKind kind);
    std::optional<EvaluationResult> evaluate(const preventiva::core::Machine& m, int newHorimeter, const QDate& readingDate) const override;
private:
    int m_threshold;
    preventiva::core::MaintenanceKind m_kind;
};

} // namespace
