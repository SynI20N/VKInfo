#include "../include/metrics_registry.h"

namespace VkInfo {

void MetricsRegistry::register_metric(std::shared_ptr<IMetric> metric) {
    std::lock_guard<std::mutex> lock(mutex_);
    metrics_.push_back(std::move(metric));
}

std::vector<std::shared_ptr<IMetric>> MetricsRegistry::get_all_metrics() {
    std::lock_guard<std::mutex> lock(mutex_);
    return metrics_;
}

} // namespace VkInfo
