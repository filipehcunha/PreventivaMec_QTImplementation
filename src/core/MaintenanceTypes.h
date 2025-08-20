#pragma once
#include <QString>
#include <QMetaType>

namespace preventiva::core {

enum class MaintenanceKind {
    Simple250,
    Complete750,
    Semiannual
};

inline QString toString(MaintenanceKind k) {
    switch (k) {
    case MaintenanceKind::Simple250: return "Simple250";
    case MaintenanceKind::Complete750: return "Complete750";
    case MaintenanceKind::Semiannual: return "Semiannual";
    }
    return "Unknown";
}

} // namespace
Q_DECLARE_METATYPE(preventiva::core::MaintenanceKind)
