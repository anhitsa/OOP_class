#ifndef COMMANDLINEOUTPUTLOG_H
#define COMMANDLINEOUTPUTLOG_H

#include <QLabel>

class CommandLineOutputLog
{
public:
    CommandLineOutputLog()=default;
    QLabel* createOutputLogLabel(std::string textToBeDisplayed="");

private:
    QLabel* outputLogLabel;

};

#endif // COMMANDLINEOUTPUTLOG_H


