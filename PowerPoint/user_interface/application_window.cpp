#include "application_window.h"

#include <QApplication>
#include <QEventLoop>
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>

ApplicationWindow::ApplicationWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createUI();
    connect(submitButton, &QPushButton::clicked, this, &ApplicationWindow::onSubmitClicked);
    setLayout(layout);
    setWindowTitle("PowerPoint");
}

void ApplicationWindow::createUI() {
    inputBox = new QLineEdit(this);
    submitButton = new QPushButton("Submit", this);

    inputBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    submitButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    layout = new QVBoxLayout;
    layout->addWidget(inputBox);
    layout->addWidget(submitButton);

    QSpacerItem* spacer = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addItem(spacer);

    imageLabel = new QLabel(this);
    layout->addWidget(imageLabel);
    imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    setMinimumSize(800, 600);

    pixmap = QPixmap(size());
    pixmap.fill(Qt::white);
}

void ApplicationWindow::onSubmitClicked()
{
    QString input = inputBox->text();
    emit userInputReceived(input);
    inputBox->clear();
}

void ApplicationWindow::exitApplication() {
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

    QApplication::quit();
}

ApplicationWindow& ApplicationWindow::getInstance()
{
    static ApplicationWindow instance;
    return instance;
}

void ApplicationWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    pixmap = pixmap.scaled(size(),  Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    imageLabel->setPixmap(pixmap);
}

