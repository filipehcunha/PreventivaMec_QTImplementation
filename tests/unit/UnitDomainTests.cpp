#include <QtTest>
#include <QDateTime>
#include "domain/SchedulingStrategy.h"
#include "domain/MaintenanceFactory.h"
using namespace Domain;

class UnitDomainTests : public QObject {
    Q_OBJECT
private slots:
    void test_time_based_strategy_nextDate() {
        TimeBasedStrategy s(6);
        const QDateTime base(QDate(2025,1,1), QTime(0,0), Qt::UTC);
        const auto next = s.nextDate(base);
        QCOMPARE(next.date(), QDate(2025,7,1)); // +6 meses
    }
    void test_usage_based_strategy_nextDate() {
        UsageBasedStrategy s(250); // 250h => ~31 dias com 8h/dia
        const QDateTime base(QDate(2025,1,1), QTime(0,0), Qt::UTC);
        const auto next = s.nextDate(base);
        QCOMPARE(next.date(), QDate(2025,2,1)); // 31 dias após 01/01/2025
    }
    void test_factory_policies() {
        auto s1 = MaintenanceFactory::make(Preventiva::SchedulePolicy::TimeBased);
        auto s2 = MaintenanceFactory::make(Preventiva::SchedulePolicy::UsageBased);
        const QDateTime base(QDate(2025,1,1), QTime(0,0), Qt::UTC);
        QVERIFY(s1->nextDate(base) != s2->nextDate(base)); // estratégias diferentes
    }
};

QTEST_MAIN(UnitDomainTests)
#include "UnitDomainTests.moc"
