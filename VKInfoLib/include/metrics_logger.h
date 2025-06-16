#ifndef METRICS_LOGGER_H_
#define METRICS_LOGGER_H_

#include <string>
#include <atomic>
#include <thread>

#include "metrics_registry.h"

namespace VkInfo {

class VKINFO_API MetricsLogger {
public:
    MetricsLogger(MetricsRegistry& registry, const std::string& filename, std::chrono::milliseconds interval);
    ~MetricsLogger();

    void start();
    void stop();

private:
    MetricsRegistry& registry_;
    std::string filename_;
    std::chrono::milliseconds interval_;
    std::atomic<bool> running_;
    std::thread worker_;

    void run();
    std::string get_current_timestamp() const;
};

} // namespace VkInfo

#endif // METRICS_LOGGER_H_
