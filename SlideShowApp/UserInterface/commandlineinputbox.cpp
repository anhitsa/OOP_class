#include "commandlineinputbox.h"

#include <QApplication>
#include <QEventLoop>
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>

CommandLineInputBox::CommandLineInputBox() : QWidget()
{
    createSublitButton();
    connect(submitButton, &QPushButton::clicked, this, &CommandLineInputBox::onSubmitClicked);
}

QVBoxLayout* CommandLineInputBox::createInputBoxLayout()
{
    inputBox = new QLineEdit(this);
    inputBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    layout = new QVBoxLayout;
    layout->addWidget(inputBox);
    layout->addWidget(submitButton);
    QSpacerItem* spacer = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addItem(spacer);
    return layout;
}

void CommandLineInputBox::createSublitButton()
{
    submitButton = new QPushButton("Submit", this);
    submitButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}

void CommandLineInputBox::onSubmitClicked()
{
    QString input = inputBox->text();
    emit userInputReceived(input);
    inputBox->clear();
}

QLineEdit* CommandLineInputBox::getInputBox() const
{
    return inputBox;
}

QPushButton* CommandLineInputBox::getSubmitButton() const
{
    return submitButton;
}

CommandLineInputBox::CommandLineInputBox(const CommandLineInputBox& other) : QWidget()
{
    inputBox = new QLineEdit(this);
    submitButton = new QPushButton("Submit", this);
    layout = new QVBoxLayout;
    connect(submitButton, &QPushButton::clicked, this, &CommandLineInputBox::onSubmitClicked);
    layout->addWidget(inputBox);
    layout->addWidget(submitButton);
    setLayout(layout);
}

CommandLineInputBox& CommandLineInputBox::operator=(const CommandLineInputBox& other)
{
    if (this != &other)
    {
        delete inputBox;
        delete submitButton;
        delete layout;

        inputBox = new QLineEdit(this);
        submitButton = new QPushButton("Submit", this);
        layout = new QVBoxLayout;

        connect(submitButton, &QPushButton::clicked, this, &CommandLineInputBox::onSubmitClicked);

        layout->addWidget(inputBox);
        layout->addWidget(submitButton);
        setLayout(layout);
    }
    return *this;
}


