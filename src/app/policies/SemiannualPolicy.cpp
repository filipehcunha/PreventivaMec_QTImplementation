#include "SemiannualPolicy.h"
#include <QDate>

using namespace preventiva::app;

std::optional<EvaluationResult> SemiannualPolicy::evaluate(const preventiva::core::Machine& m, int, const QDate& readingDate) const {
    if (m.lastAnyMaintenanceDate().addMonths(6) <= readingDate) {
        EvaluationResult r;
        r.kind = preventiva::core::MaintenanceKind::Semiannual;
        r.dueDate = readingDate;
        r.reason = ">=6m";
        return r;
    }
    return std::nullopt;
}
