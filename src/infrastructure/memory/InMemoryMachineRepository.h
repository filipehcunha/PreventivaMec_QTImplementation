#pragma once
#include "../../app/IMachineRepository.h"
#include <QHash>

namespace preventiva::infra {

class InMemoryMachineRepository : public preventiva::app::IMachineRepository {
public:
    bool save(const preventiva::core::Machine& m) override;
    std::optional<preventiva::core::Machine> get(const QString& id) const override;
    QVector<preventiva::core::Machine> all() const override;
private:
    QHash<QString, preventiva::core::Machine> m_store;
};

} // namespace
