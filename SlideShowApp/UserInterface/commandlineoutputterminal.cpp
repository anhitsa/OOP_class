#include "commandlineoutputterminal.h"

QLabel* CommandLineOutputTerminal::createOutputTerminalLabel(std::string textToBeDisplayed)
{
    QString labelText = QString::fromStdString(textToBeDisplayed);
    outputTerminalLabel = new QLabel(labelText);
    outputTerminalLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    return outputTerminalLabel;
}
