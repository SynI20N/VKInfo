#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

#include "../include/metrics_logger.h"

namespace VkInfo {

MetricsLogger::MetricsLogger(MetricsRegistry& registry,
                            const std::string& filename,
                            std::chrono::milliseconds interval)
: registry_(registry),
    filename_(filename),
    interval_(interval),
    running_(false) {}

MetricsLogger::~MetricsLogger() {
    stop();
}

void MetricsLogger::start() {
    if (running_) return;
    running_ = true;
    worker_ = std::thread(&MetricsLogger::run, this);
}

void MetricsLogger::stop() {
    if (!running_) return;
    running_ = false;
    if (worker_.joinable()) {
        worker_.join();
    }
}

std::vector<std::shared_ptr<IMetric>> MetricsLogger::get_all_metrics() {
    return registry_.get_all_metrics();
}

std::string MetricsLogger::get_current_timestamp() const {
    using namespace std::chrono;

    auto now = system_clock::now();
    auto time = system_clock::to_time_t(now);
    auto ms = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;

    std::ostringstream oss;
    oss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S")
        << "." << std::setw(3) << std::setfill('0') << ms.count();
    return oss.str();
}

void MetricsLogger::run() {
    std::ofstream out(filename_, std::ios::app);
    while (running_) {
        auto now = get_current_timestamp();
        std::ostringstream line;
        line << now;

        for (auto& metric : registry_.get_all_metrics()) {
            line << " \"" << metric->get_name() << "\" " << metric->get_value_and_reset();
        }

        out << line.str() << std::endl;
        out.flush();
        std::this_thread::sleep_for(interval_);
    }
}

} // namespace VkInfo
