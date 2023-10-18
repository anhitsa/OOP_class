#ifndef APPLICATION_WINDOW_H
#define APPLICATION_WINDOW_H

#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include <QVBoxLayout>

class ApplicationWindow : public QMainWindow
{
    Q_OBJECT

public:
    static ApplicationWindow& getInstance();
    static void initialize() { static ApplicationWindow instance; }
    static void exitApplication();
    void setBlankScreen();

private:
    ApplicationWindow(QWidget *parent = nullptr);
    ~ApplicationWindow() {}
    ApplicationWindow(const ApplicationWindow&) = delete;
    ApplicationWindow& operator=(const ApplicationWindow&) = delete;
    void createUI();

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
