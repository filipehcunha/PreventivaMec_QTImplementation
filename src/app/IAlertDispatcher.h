#pragma once
#include <QString>

namespace preventiva::app {

struct Alert {
    QString machineId;
    QString subject;
    QString body;
};

class IAlertDispatcher {
public:
    virtual ~IAlertDispatcher() = default;
    virtual void dispatch(const Alert& a) = 0;
};

} // namespace
