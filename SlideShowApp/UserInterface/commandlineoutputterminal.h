#ifndef COMMANDLINEOUTPUTTERMINAL_H
#define COMMANDLINEOUTPUTTERMINAL_H

#include <QLabel>

class CommandLineOutputTerminal
{
public:
    CommandLineOutputTerminal()=default;
    QLabel* createOutputTerminalLabel(std::string textToBeDisplayed="");

private:
    QLabel* outputTerminalLabel;

};

#endif // COMMANDLINEOUTPUTTERMINAL_H
