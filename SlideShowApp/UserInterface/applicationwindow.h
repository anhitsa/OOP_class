#ifndef APPLICATION_WINDOW_H
#define APPLICATION_WINDOW_H

#include <QFileInfo>
#include <QEventLoop>
#include <QMainWindow>
#include <QMessageBox>
#include <QLabel>
#include <QStringLiteral>
#include <QTimer>
#include <QVBoxLayout>

#include "commandlineinputbox.h"
#include "commandlineoutputLog.h"

class ApplicationWindow : public QMainWindow
{
    Q_OBJECT

public:
    ApplicationWindow(std::shared_ptr<CommandLineInputBox>, std::shared_ptr<CommandLineOutputLog>, QWidget *parent = nullptr);
    void static exitApplicationWindowWithMessage();
    void setBlankScreen();
    QPushButton* getUndoButton() const;
    QPushButton* getRedoButton() const;
    void displayTextOnOutputTerminal(const std::string);

public:
    QLabel* imageLabel;
    QPixmap pixmap;

private:
    void createUI();
    QLayout* determineUndoRedoButtonsLayout();

public slots:
    void resizeEvent(QResizeEvent* event);

private:
    std::shared_ptr<CommandLineInputBox> commandLineInputBox;
    std::shared_ptr<CommandLineOutputLog> commandLineOutputLog;
    QPushButton* undoButton;
    QPushButton* redoButton;
    QVBoxLayout* layout;

};

#endif // APPLICATION_WINDOW_H
