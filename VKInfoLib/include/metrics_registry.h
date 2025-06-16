#ifndef METRICS_REGISTRY_H_
#define METRICS_REGISTRY_H_

#include <vector>
#include <memory>
#include <mutex>

#include "metric.h"

namespace VkInfo {
    
class VKINFO_API MetricsRegistry {
public:
    void register_metric(std::shared_ptr<IMetric> metric);
    std::vector<std::shared_ptr<IMetric>> get_all_metrics();

private:
    std::vector<std::shared_ptr<IMetric>> metrics_;
    std::mutex mutex_;
};

} // namespace VkInfo

#endif // METRICS_REGISTRY_H_
