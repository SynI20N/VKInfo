#ifndef MAINWIDGET_H_
#define MAINWIDGET_H_

#include "../../VKInfoLib/include/metrics_logger.h"

#include <QWidget>
#include <QVBoxLayout>
#include <memory>

/**
 * @brief Forward declarations for Qt widgets.
 */
class QPushButton;
class QTextBrowser;

/**
 * @brief MainWidget is a Qt widget that displays buttons for each metric and allows setting random values.
 *
 * This widget dynamically creates a button for each metric registered in the VkInfo::MetricsRegistry.
 * When a button is clicked, a random value is set to the corresponding metric, and an entry is shown
 * in the text browser. The widget also manages a background logging thread through MetricsLogger.
 */
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructs the MainWidget.
     * 
     * @param logger A pointer to the VkInfo::MetricsLogger instance. Ownership is transferred.
     * @param parent Parent widget (optional).
     */
    explicit MainWidget(VkInfo::MetricsLogger* logger, QWidget *parent = nullptr);

    /**
     * @brief Destructor for MainWidget.
     * 
     * Cleans up dynamically allocated Qt widgets and ensures the logger is stopped.
     */
    virtual ~MainWidget();

private:
    QTextBrowser* textBrowser_;  ///< Displays messages when random values are set.
    std::unique_ptr<VkInfo::MetricsLogger> logger_; ///< Background logger for metric output.
    std::vector<std::shared_ptr<VkInfo::IMetric>> metrics_; ///< Stored metrics used for button generation.

    /**
     * @brief Creates buttons dynamically for each metric and connects them to set random values.
     * 
     * @param metrics A list of shared pointers to IMetric objects.
     * @param parentLayout A pointer to the QVBoxLayout where buttons will be added.
     */
    void create_metric_buttons(const std::vector<std::shared_ptr<VkInfo::IMetric>>& metrics,
                               QVBoxLayout* parentLayout);
};

#endif // MAINWIDGET_H_
