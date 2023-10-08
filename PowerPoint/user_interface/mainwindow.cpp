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
    inputBox = new QLineEdit(this);
    layout->addWidget(inputBox);
    QPushButton* submitButton = new QPushButton("Submit", this);
    layout->addWidget(submitButton);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(submitButton, &QPushButton::clicked, this, &MainWindow::onSubmitClicked);

    setLayout(layout);
    setWindowTitle("Application");
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

void MainWindow::printToScreen(const Slide& slide)
{
    // to be implemented
}
