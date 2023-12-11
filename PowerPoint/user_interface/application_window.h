#ifndef APPLICATION_WINDOW_H
#define APPLICATION_WINDOW_H

#include "uicomponent.h"

#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include <QVBoxLayout>

//TK:  Window objects should not be singletone, overall UI should be thought organized better way
class ApplicationWindow : public QMainWindow, public UIComponent
{
    Q_OBJECT

public:
    static ApplicationWindow& getInstance();
    void static exitApplication();
    void setBlankScreen() override;

private:
    ApplicationWindow(QWidget *parent = nullptr);
    ~ApplicationWindow() {}
    ApplicationWindow(const ApplicationWindow&) = delete;
    ApplicationWindow& operator=(const ApplicationWindow&) = delete;
    void createUI() override;

public slots:
    void onSubmitClicked();
    void resizeEvent(QResizeEvent* event);

private:
    QLineEdit *inputBox;
    QPushButton* submitButton;
    QVBoxLayout* layout;

public:
    QLabel* imageLabel;
    QPixmap pixmap;

signals:
    void userInputReceived(const QString& input);

};

#endif // APPLICATION_WINDOW_H
