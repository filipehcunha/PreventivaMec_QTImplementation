#pragma once
#include "../../app/IAlertDispatcher.h"
#include <QVector>

namespace preventiva::infra {

class FakeEmailDispatcher : public preventiva::app::IAlertDispatcher {
public:
    void dispatch(const preventiva::app::Alert& a) override;
    const QVector<preventiva::app::Alert>& sent() const { return m_sent; }
    void clear() { m_sent.clear(); }
private:
    QVector<preventiva::app::Alert> m_sent;
};

} // namespace
