#ifndef ATOMIC_METRIC_H_
#define ATOMIC_METRIC_H_

#include <string>
#include <atomic>
#include <stdexcept>
#include <random>

#include "metric.h"

namespace VkInfo {

template<typename T>
class VKINFO_API AtomicMetric : public IMetric {
public:
    AtomicMetric(const std::string& name, T max, T min) 
        : name_(name), value_(0), max_(max), min_(min) {}

    void set(T value)  {
        validate(value);
        value_ = value;
    }

    void set_random_value() override {
        using dist = std::uniform_real_distribution<double>;

        static thread_local std::mt19937 gen(std::random_device{}());
        dist real_dist;

        real_dist = dist(static_cast<double>(min_), static_cast<double>(max_));
        value_ = static_cast<T>(real_dist(gen));
    }

    std::string get_name() const override {
        return name_;
    }

    std::string get_value_and_reset() override {
        T val = value_.exchange(0);
        return std::to_string(val);
    }

private:
    std::string name_;
    std::atomic<T> value_;
    T max_;
    T min_;

    void validate(T& value) {
        if(value > max_) {
            throw std::domain_error("metric value exceeds max value");
        }
        else if(value < min_) {
            throw std::domain_error("metric value underflows");
        }
    }
};

} // namespace VkInfo

#endif // ATOMIC_METRIC_H_
