#ifndef APPLICATION_WINDOW_H
#define APPLICATION_WINDOW_H

#include <QEventLoop>
#include <QMainWindow>
#include <QMessageBox>
#include <QLabel>
#include <QTimer>
#include <QVBoxLayout>

#include "commandlineinputbox.h"
#include "commandlineoutputterminal.h"

class ApplicationWindow : public QMainWindow
{
    Q_OBJECT

public:
    ApplicationWindow(std::shared_ptr<CommandLineInputBox>, std::shared_ptr<CommandLineOutputTerminal>, QWidget *parent = nullptr);
    void static exitApplicationWindowWithMessage();
    void setBlankScreen();
    void displayTextOnOutputTerminal(const std::string);

public:
    QLabel* imageLabel;
    QPixmap pixmap;

private:
    void createUI();

public slots:
    void resizeEvent(QResizeEvent* event);

private:
    std::shared_ptr<CommandLineInputBox> commandLineInputBox;
    std::shared_ptr<CommandLineOutputTerminal> commandLineOutputTerminal;
    QVBoxLayout* layout;

};

#endif // APPLICATION_WINDOW_H
