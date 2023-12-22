#include "applicationwindow.h"

ApplicationWindow::ApplicationWindow(std::shared_ptr<CommandLineInputBox> commandLineInputBox,
                                     std::shared_ptr<CommandLineOutputTerminal> commandLineOutputTerminal,
                                     QWidget *parent)
    : QMainWindow(parent), commandLineInputBox(commandLineInputBox), commandLineOutputTerminal(commandLineOutputTerminal)
{
    createUI();
    setWindowTitle("PowerPoint");
    setAcceptDrops(true);
}

void ApplicationWindow::createUI()
{
    layout = commandLineInputBox->createInputBoxLayout();
    imageLabel = new QLabel(this);
    layout->addWidget(imageLabel);
    imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    auto outputTerminalLabel = commandLineOutputTerminal->createOutputTerminalLabel();
    layout->addWidget(outputTerminalLabel);
    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    setMinimumSize(800, 600);
    pixmap = QPixmap(size());
    pixmap.fill(Qt::white);
    show();
}

void ApplicationWindow::exitApplicationWindowWithMessage()
{
    QMessageBox exitingMessage;
    exitingMessage.setText("Exiting PowerPoint...");
    exitingMessage.show();

    QTimer timer;
    timer.setSingleShot(true);
    QObject::connect(&timer, &QTimer::timeout, [&exitingMessage]() {
        exitingMessage.close();
    });
    timer.start(2000);

    QEventLoop loop;
    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    loop.exec();
}

void ApplicationWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    pixmap = pixmap.scaled(size(),  Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    imageLabel->setPixmap(pixmap);
}

void ApplicationWindow::setBlankScreen()
{
    pixmap = QPixmap(size());
    pixmap.fill(Qt::white);
    imageLabel->setPixmap(pixmap.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    imageLabel->show();
}

void ApplicationWindow::displayTextOnOutputTerminal(const std::string textToBeDisplayed)
{
    auto outputTerminalLabel = commandLineOutputTerminal->createOutputTerminalLabel(textToBeDisplayed);
    layout->addWidget(outputTerminalLabel);
}
