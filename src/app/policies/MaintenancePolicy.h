#pragma once
#include <optional>
#include <QString>
#include <QDate>
#include "../../core/Machine.h"
#include "../../core/MaintenanceTypes.h"

namespace preventiva::app {

struct EvaluationResult {
    std::optional<preventiva::core::MaintenanceKind> kind;
    QDate dueDate;
    QString reason;
};

class MaintenancePolicy {
public:
    virtual ~MaintenancePolicy() = default;
    virtual std::optional<EvaluationResult> evaluate(const preventiva::core::Machine& m, int newHorimeter, const QDate& readingDate) const = 0;
};

} // namespace
