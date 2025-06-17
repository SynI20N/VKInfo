#ifndef ATOMIC_METRIC_H_
#define ATOMIC_METRIC_H_

#include <string>
#include <atomic>
#include <stdexcept>
#include <random>

#include "metric.h"

namespace VkInfo {

/**
 * @brief A thread-safe metric implementation using atomic variables.
 * 
 * AtomicMetric represents a numeric metric (e.g., CPU usage, request count) that can be safely
 * updated and accessed across multiple threads. It supports setting values directly or assigning
 * a random value within a defined range. Upon retrieval via get_value_and_reset(), the value is reset.
 * 
 * @tparam T The numeric type of the metric (e.g., int, float, double).
 */
template<typename T>
class VKINFO_API AtomicMetric : public IMetric {
public:
    /**
     * @brief Constructs an atomic metric with the given name and allowed range.
     * 
     * @param name Name of the metric.
     * @param max Maximum allowed value for the metric.
     * @param min Minimum allowed value for the metric.
     */
    AtomicMetric(const std::string& name, T max, T min) 
        : name_(name), value_(0), max_(max), min_(min) {}

    /**
     * @brief Sets the metric to a specific value.
     * 
     * @param value The new value to assign to the metric.
     * @throws std::domain_error if value is out of [min_, max_] bounds.
     */
    void set(T value) {
        validate(value);
        value_ = value;
    }

    /**
     * @brief Sets the metric to a randomly generated value within its valid range.
     * 
     * This function is thread-safe and uses a thread-local random number generator.
     */
    void set_random_value() override {
        using dist = std::uniform_real_distribution<double>;
        static thread_local std::mt19937 gen(std::random_device{}());
        dist real_dist(static_cast<double>(min_), static_cast<double>(max_));
        value_ = static_cast<T>(real_dist(gen));
    }

    /**
     * @brief Returns the name of the metric.
     * 
     * @return std::string The metric name.
     */
    std::string get_name() const override {
        return name_;
    }

    /**
     * @brief Returns the value of the metric.
     * 
     * @return T - value of the metric
     */
    T get_value() const {
        return value_;
    }

    /**
     * @brief Returns the current value and resets it to zero atomically.
     * 
     * @return std::string The value (converted to string) before reset.
     */
    std::string get_value_and_reset() override {
        T val = value_.exchange(0);
        return std::to_string(val);
    }

private:
    std::string name_;         ///< Name of the metric.
    std::atomic<T> value_;     ///< Atomic storage for the current value.
    T max_;                    ///< Maximum allowed value.
    T min_;                    ///< Minimum allowed value.

    /**
     * @brief Validates that a value is within the defined range.
     * 
     * @param value The value to validate.
     * @throws std::domain_error if the value is outside [min_, max_].
     */
    void validate(T& value) {
        if (value > max_) {
            throw std::domain_error("metric value exceeds max value");
        } else if (value < min_) {
            throw std::domain_error("metric value underflows");
        }
    }
};

} // namespace VkInfo

#endif // ATOMIC_METRIC_H_
