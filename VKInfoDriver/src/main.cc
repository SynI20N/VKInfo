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

    VkInfo::MetricsLogger logger(registry, "metrics.log", std::chrono::seconds(1));
    logger.start();

    // Имитируем работу приложения
    for (int i = 0; i < 100; ++i) {
        cpuUtil->set(1.5 * (i % 3));
        httpReqs->set(10 + i);

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    logger.stop();

    QApplication a(argc, argv);

    MainWidget w;
    w.show();

    return a.exec();
}

