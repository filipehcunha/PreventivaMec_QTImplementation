#include "PolicyComposite.h"

using namespace preventiva::app;

void PolicyComposite::add(std::shared_ptr<MaintenancePolicy> p) {
    m_policies.push_back(std::move(p));
}

std::optional<EvaluationResult> PolicyComposite::evaluate(const preventiva::core::Machine& m, int newHorimeter, const QDate& readingDate) const {
    // Return the earliest (first matched) policy evaluation.
    for (const auto& p : m_policies) {
        if (auto r = p->evaluate(m, newHorimeter, readingDate)) {
            return r;
        }
    }
    return std::nullopt;
}
