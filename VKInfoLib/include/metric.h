#ifndef METRIC_H_
#define METRIC_H_

#include <string>

#include "export.h"

namespace VkInfo {

/**
 * @brief Interface for all metric types.
 * 
 * The IMetric interface defines the basic operations that all metrics must implement.
 * Metrics represent named values that can be updated over time and periodically reported or reset.
 */
class VKINFO_API IMetric {
public:
    /**
     * @brief Virtual destructor for safe polymorphic deletion.
     */
    virtual ~IMetric() = default;

    /**
     * @brief Returns the name of the metric.
     * 
     * @return A string containing the metric's name.
     */
    virtual std::string get_name() const = 0;

    /**
     * @brief Retrieves the current value of the metric and resets it.
     * 
     * This method is typically called periodically (e.g., by a logger) to
     * capture and clear the accumulated value.
     * 
     * @return The value of the metric as a string.
     */
    virtual std::string get_value_and_reset() = 0;

    /**
     * @brief Assigns a new random value to the metric.
     * 
     * This method is primarily used for testing or demonstration purposes.
     */
    virtual void set_random_value() = 0;
};

} // namespace VkInfo

#endif // METRIC_H_
