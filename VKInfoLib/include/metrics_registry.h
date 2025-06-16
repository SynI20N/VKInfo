#ifndef METRICS_REGISTRY_H_
#define METRICS_REGISTRY_H_

#include <vector>
#include <memory>
#include <mutex>

#include "metric.h"

namespace VkInfo {

/**
 * @brief Registry for managing and storing metrics.
 *
 * MetricsRegistry maintains a thread-safe collection of metrics.
 * It allows registration of new metrics and provides access to all registered metrics.
 */
class VKINFO_API MetricsRegistry {
public:
    /**
     * @brief Registers a new metric.
     *
     * Thread-safe method to add a metric to the registry.
     *
     * @param metric Shared pointer to the metric to register.
     */
    void register_metric(std::shared_ptr<IMetric> metric);

    /**
     * @brief Retrieves all registered metrics.
     *
     * Thread-safe method to get a snapshot of all metrics currently registered.
     *
     * @return Vector of shared pointers to all registered metrics.
     */
    std::vector<std::shared_ptr<IMetric>> get_all_metrics();

private:
    std::vector<std::shared_ptr<IMetric>> metrics_; ///< Container holding registered metrics.
    std::mutex mutex_;                              ///< Mutex to protect access to metrics_.
};

} // namespace VkInfo

#endif // METRICS_REGISTRY_H_
