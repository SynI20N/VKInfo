#include "../../VKInfoLib/include/atomic_metric.h"

#include <gtest/gtest.h>
#include <memory>

namespace VkInfoTest {
    class AtomicMetricTest : public testing::Test {
    public:
        AtomicMetricTest() {
            m1_ = std::make_unique<VkInfo::AtomicMetric<double>>("Test", 100.0, 0.0);
        }
    protected:
        void SetUp() override {
            m1_->set(3.14);
        }

        virtual void TearDown() {

        }

        std::unique_ptr<VkInfo::AtomicMetric<double>> m1_;
    };


    TEST_F(AtomicMetricTest, TestFlush) {
        m1_->get_value_and_reset();

        ASSERT_EQ(m1_->get_value(), 0);
    }
} // namespace VkInfoTest
