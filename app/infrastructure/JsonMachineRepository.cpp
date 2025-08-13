#include "JsonMachineRepository.h"

JsonMachineRepository::JsonMachineRepository(const QString& path): m_path(path) {}

void JsonMachineRepository::ensureLoaded() const {
    if (!m_cache.isEmpty()) return;
    QFile f(m_path);
    if (!f.open(QIODevice::ReadOnly)) {
        m_cache = { {"M1","Escavadeira ZX200",120}, {"M2","Pá Carregadeira 950M",430} };
        return;
    }
    const auto doc = QJsonDocument::fromJson(f.readAll());
    if (!doc.isArray()) return;
    for (const auto& v: doc.array()) {
        const auto o = v.toObject();
        m_cache.push_back({ o["id"].toString(), o["model"].toString(), o["hours"].toInt() });
    }
}
QVector<Preventiva::Machine> JsonMachineRepository::list() const { ensureLoaded(); return m_cache; }
Preventiva::Machine JsonMachineRepository::get(const QString& id) const { ensureLoaded(); for(const auto& m: m_cache) if(m.id==id) return m; return {"","",0}; }
void JsonMachineRepository::save(const Preventiva::Machine& m) {
    ensureLoaded(); bool found=false; for(auto& it: m_cache) if(it.id==m.id){ it=m; found=true; break; } if(!found) m_cache.push_back(m);
    QJsonArray arr; for(const auto& it: m_cache){ QJsonObject o; o["id"]=it.id; o["model"]=it.model; o["hours"]=it.hours; arr.push_back(o); }
    QFile f(m_path); f.open(QIODevice::WriteOnly); f.write(QJsonDocument(arr).toJson());
}
