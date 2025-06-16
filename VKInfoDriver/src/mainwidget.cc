#include <QtWidgets>
#include <iostream>
#include <memory>

#include "../include/mainwidget.h"

void MainWidget::create_metric_buttons(const std::vector<std::shared_ptr<VkInfo::IMetric>>& metrics,
                                       QVBoxLayout* parentLayout) {
    for (const auto& metric : metrics) {
        QString buttonText = QString::fromStdString("Set random for: " + metric->get_name());
        QPushButton* button = new QPushButton(buttonText);
        parentLayout->addWidget(button);

        connect(button, &QPushButton::clicked, [metric, this]() {
            metric->set_random_value();
            QString msg = QString("Random value set for \"%1\"").arg(QString::fromStdString(metric->get_name()));
            textBrowser_->append(msg);
        });
    }
}

MainWidget::MainWidget(VkInfo::MetricsLogger* logger, QWidget *parent)
    : QWidget(parent)
{
    logger_ = std::unique_ptr<VkInfo::MetricsLogger>(logger);
    logger_->start();

    QVBoxLayout* mainLayout = new QVBoxLayout;

    textBrowser_ = new QTextBrowser();
    mainLayout->addWidget(textBrowser_);

    metrics_ = logger_->get_all_metrics();

    create_metric_buttons(metrics_, mainLayout);

    setLayout(mainLayout);
    setWindowTitle(tr("VKInfo Metrics"));
}

MainWidget::~MainWidget()
{
   delete textBrowser_;
}

