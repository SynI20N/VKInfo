#ifndef METRICS_LOGGER_H_
#define METRICS_LOGGER_H_

#include <string>
#include <atomic>
#include <thread>

#include "metrics_registry.h"

namespace VkInfo {

/**
 * @brief Periodically logs metric values to a file.
 * 
 * MetricsLogger runs in a background thread, collecting metric values from a MetricsRegistry
 * at fixed intervals and writing them to a log file with timestamps. After logging, each metric
 * is reset. This logger is thread-safe and non-blocking for metric producers.
 */
class VKINFO_API MetricsLogger {
public:
    /**
     * @brief Constructs a MetricsLogger instance.
     * 
     * @param registry Reference to the MetricsRegistry containing all metrics to log.
     * @param filename Name of the file to write log entries to.
     * @param interval Logging interval (e.g., every second).
     */
    MetricsLogger(MetricsRegistry& registry, const std::string& filename, std::chrono::milliseconds interval);

    /**
     * @brief Destructor for MetricsLogger.
     * 
     * Ensures the background thread is stopped before destruction.
     */
    ~MetricsLogger();

    /**
     * @brief Starts the background logging thread.
     * 
     * Logs metric data to the file at the specified interval.
     */
    void start();

    /**
     * @brief Stops the background logging thread safely.
     */
    void stop();

    /**
     * @brief Retrieves all currently registered metrics from the registry.
     * 
     * @return A vector of shared pointers to IMetric instances.
     */
    std::vector<std::shared_ptr<IMetric>> get_all_metrics();

private:
    MetricsRegistry& registry_;                 ///< Reference to the metric registry.
    std::string filename_;                      ///< Output log file name.
    std::chrono::milliseconds interval_;        ///< Logging frequency.
    std::atomic<bool> running_;                 ///< Indicates if the logger is running.
    std::thread worker_;                        ///< Background thread for logging.

    /**
     * @brief Main logging loop executed in a background thread.
     * 
     * Gathers metrics, writes them to the file, and resets them.
     */
    void run();

    /**
     * @brief Gets the current system time as a formatted timestamp string.
     * 
     * @return Timestamp in the format "YYYY-MM-DD HH:MM:SS.mmm".
     */
    std::string get_current_timestamp() const;
};

} // namespace VkInfo

#endif // METRICS_LOGGER_H_
