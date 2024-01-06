#include "commandlineoutputlog.h"

QLabel* CommandLineOutputLog::createOutputLogLabel(std::string textToBeDisplayed)
{
    if (outputLogLabel)
        outputLogLabel->clear();
    QString labelText = QString::fromStdString(textToBeDisplayed);
    outputLogLabel = new QLabel(labelText);
    outputLogLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    return outputLogLabel;
}
