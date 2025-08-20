#include "InMemoryMachineRepository.h"

using namespace preventiva::infra;
using namespace preventiva::core;

bool InMemoryMachineRepository::save(const Machine& m) {
    m_store.insert(m.id(), m);
    return true;
}

std::optional<Machine> InMemoryMachineRepository::get(const QString& id) const {
    if (m_store.contains(id)) return m_store.value(id);
    return std::nullopt;
}

QVector<Machine> InMemoryMachineRepository::all() const {
    return m_store.values().toVector();
}
