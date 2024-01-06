#include "applicationwindow.h"

ApplicationWindow::ApplicationWindow(std::shared_ptr<CommandLineInputBox> commandLineInputBox,
                                     std::shared_ptr<CommandLineOutputLog> commandLineOutputTerminal,
                                     QWidget *parent)
    : QMainWindow(parent), commandLineInputBox(commandLineInputBox), commandLineOutputLog(commandLineOutputTerminal)
{
    layout = new QVBoxLayout;
    createUI();
    setWindowTitle("PowerPoint");
    setAcceptDrops(true);
}

void ApplicationWindow::createUI()
{
    auto inputBoxLayout = commandLineInputBox->createInputBoxLayout();
    layout->addLayout(inputBoxLayout);
    auto undoRedoButtonsLayout = determineUndoRedoButtonsLayout();
    layout->addLayout(undoRedoButtonsLayout);
    imageLabel = new QLabel(this);
    layout->addWidget(imageLabel);
    imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    auto outputLogLabel = commandLineOutputLog->createOutputLogLabel();
    layout->addWidget(outputLogLabel);

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
    auto outputTerminalLabel = commandLineOutputLog->createOutputLogLabel(textToBeDisplayed);
    layout->addWidget(outputTerminalLabel);
}

QLayout* ApplicationWindow::determineUndoRedoButtonsLayout()
{
    const QString imageDir = QFileInfo(QStringLiteral(__FILE__)).path();
    QHBoxLayout* undoRedoLayout = new QHBoxLayout;

    undoButton = new QPushButton(QIcon(imageDir + "/undo_icon.png"), "");
    undoButton->setToolTip("Undo");
    undoButton->setFixedSize(30, 30);

    redoButton = new QPushButton(QIcon(imageDir + "/redo_icon.png"), "");
    redoButton->setToolTip("Redo");
    redoButton->setFixedSize(30, 30);

    undoRedoLayout->addWidget(undoButton);
    undoRedoLayout->addWidget(redoButton);
    undoRedoLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));

    return undoRedoLayout;
}


QPushButton* ApplicationWindow::getUndoButton() const
{
    return undoButton;
}

QPushButton* ApplicationWindow::getRedoButton() const
{
    return redoButton;
}

