#pragma once
#include <optional>
#include <QVector>
#include "../core/Machine.h"

namespace preventiva::app {

class IMachineRepository {
public:
    virtual ~IMachineRepository() = default;
    virtual bool save(const preventiva::core::Machine& m) = 0;
    virtual std::optional<preventiva::core::Machine> get(const QString& id) const = 0;
    virtual QVector<preventiva::core::Machine> all() const = 0;
};

} // namespace
