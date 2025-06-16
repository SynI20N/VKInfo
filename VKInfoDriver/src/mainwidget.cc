#include <QtWidgets>
#include <iostream>

#include "../include/mainwidget.h"

void MainWidget::push_button_clicked() {
   std::cout << "Pushed button1" << '\n';
}

// Constructor for main widget
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
   button_ = new QPushButton(tr("Generate HTTP metric"));
   button2_ = new QPushButton(tr("Generate CPU metric"));
   textBrowser_ = new QTextBrowser();

   QGridLayout *mainLayout = new QGridLayout;
   mainLayout->addWidget(button_,0,0);
   mainLayout->addWidget(button2_,1,0);
   mainLayout->addWidget(textBrowser_,2,0);
   setLayout(mainLayout);
   setWindowTitle(tr("VKInfoDriver"));
   connect( button_, SIGNAL( clicked() ), this, SLOT(push_button_clicked()));
}

// Destructor
MainWidget::~MainWidget()
{
   delete button_;
   delete button2_;
   delete textBrowser_;
}

