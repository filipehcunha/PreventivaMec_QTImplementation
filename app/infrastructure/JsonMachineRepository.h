#pragma once
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include "preventiva/IMachineRepository.h"

/**
 * @brief Implementação simples de repositório usando JSON local (demo).
 * @details Demonstra o padrão Repository e separação de camadas (infraestrutura).
 */
class JsonMachineRepository : public Preventiva::IMachineRepository {
public:
    explicit JsonMachineRepository(const QString& path);
    QVector<Preventiva::Machine> list() const override;
    Preventiva::Machine get(const QString& id) const override;
    void save(const Preventiva::Machine& m) override;

private:
    QString m_path;
    mutable QVector<Preventiva::Machine> m_cache;
    void ensureLoaded() const;
};
