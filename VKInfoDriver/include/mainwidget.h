#ifndef MAINWIDGET_H_
#define MAINWIDGET_H_

#include <QWidget>

class QPushButton;
class QTextBrowser;

// This is the declaration of our MainWidget class
// The definition/implementation is in mainwidget.cpp
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0); //Constructor
    virtual ~MainWidget(); // Destructor

private:
   QPushButton* button_;
   QPushButton* button2_;
   QTextBrowser* textBrowser_;

public slots:
   void push_button_clicked();
};

#endif // MAINWIDGET_H_

