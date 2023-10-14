#include "mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVBoxLayout* layout = new QVBoxLayout;
    createInputLayout(layout);

    connect(submitButton, &QPushButton::clicked, this, &MainWindow::onSubmitClicked);

    setLayout(layout);
    setWindowTitle("PowerPoint");
}

void MainWindow::createInputLayout(QVBoxLayout* layout)
{
    inputBox = new QLineEdit(this);
    layout->addWidget(inputBox);

    submitButton = new QPushButton("Submit", this);
    layout->addWidget(submitButton);

    QSpacerItem* spacer = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addItem(spacer);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void MainWindow::onSubmitClicked()
{
    QString input = inputBox->text();
    emit userInputReceived(input);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exitApplication() {
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





















