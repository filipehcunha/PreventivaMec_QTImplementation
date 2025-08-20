#pragma once
#include "MaintenancePolicy.h"

namespace preventiva::app {

class SemiannualPolicy : public MaintenancePolicy {
public:
    std::optional<EvaluationResult> evaluate(const preventiva::core::Machine& m, int newHorimeter, const QDate& readingDate) const override;
};

} // namespace
