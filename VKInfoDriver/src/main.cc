#include "../../VKInfoLib/include/metrics_registry.h"
#include "../../VKInfoLib/include/metrics_logger.h"
#include "../../VKInfoLib/include/atomic_metric.h"

#include <iostream>
#include <QtWidgets>

#include "../include/mainwidget.h"

int main(int argc, char** argv)
{
    std::cout << "Running driver code" << '\n';
    
    VkInfo::MetricsRegistry registry;

    auto cpuUtil = std::make_shared<VkInfo::AtomicMetric<double>>("CPU", 16.0, 0.0);
    auto httpReqs = std::make_shared<VkInfo::AtomicMetric<int>>("HTTP requests RPS", INT_MAX, 0);
    auto vkStock = std::make_shared<VkInfo::AtomicMetric<float>>("VKCO (RUB)", 10000.0, -10000.0);
    auto avgCpuLoad = std::make_shared<VkInfo::AtomicMetric<double>>("avg CPU LOAD", 100.0, 0);

    registry.register_metric(cpuUtil);
    registry.register_metric(httpReqs);
    registry.register_metric(vkStock);
    registry.register_metric(avgCpuLoad);

    QApplication a(argc, argv);

    VkInfo::MetricsLogger* logger = new VkInfo::MetricsLogger(registry, "metrics.log", std::chrono::seconds(1));
    MainWidget w(logger);
    w.show();

    return a.exec();
}

