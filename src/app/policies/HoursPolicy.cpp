#include "HoursPolicy.h"

using namespace preventiva::app;
using namespace preventiva::core;

HoursPolicy::HoursPolicy(int thresholdHours, MaintenanceKind kind) : m_threshold(thresholdHours), m_kind(kind) {}

std::optional<EvaluationResult> HoursPolicy::evaluate(const Machine& m, int newHorimeter, const QDate& readingDate) const {
    int base = (m_kind == MaintenanceKind::Simple250) ? m.lastSimpleAtHours() : m.lastCompleteAtHours();
    int delta = newHorimeter - base;
    if (delta >= m_threshold) {
        EvaluationResult r;
        r.kind = m_kind;
        r.dueDate = readingDate;
        r.reason = QString(">=%1h").arg(m_threshold);
        return r;
    }
    return std::nullopt;
}
