#include "FakeEmailDispatcher.h"

using namespace preventiva::infra;
using namespace preventiva::app;

void FakeEmailDispatcher::dispatch(const Alert& a) {
    m_sent.push_back(a);
}
