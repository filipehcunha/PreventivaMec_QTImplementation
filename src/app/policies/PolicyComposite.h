#pragma once
#include "MaintenancePolicy.h"
#include <QVector>
#include <memory>

namespace preventiva::app {

class PolicyComposite : public MaintenancePolicy {
public:
    void add(std::shared_ptr<MaintenancePolicy> p);
    std::optional<EvaluationResult> evaluate(const preventiva::core::Machine& m, int newHorimeter, const QDate& readingDate) const override;
private:
    QVector<std::shared_ptr<MaintenancePolicy>> m_policies;
};

} // namespace
