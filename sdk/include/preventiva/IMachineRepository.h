#pragma once
#include <QString>
#include <QVector>
#include "Types.h"

namespace Preventiva {
class IMachineRepository {
public:
    virtual ~IMachineRepository() = default;
    virtual QVector<Machine> list() const = 0;
    virtual Machine get(const QString& id) const = 0;
    virtual void save(const Machine& m) = 0;
};
} // namespace Preventiva
