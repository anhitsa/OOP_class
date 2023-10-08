#ifndef USERINPUTHANDLER_H
#define USERINPUTHANDLER_H

#include <QDebug>
#include <QObject>
#include <QString>
#include <sstream>

class UserInputHandler : public QObject
{
    Q_OBJECT

public:
    UserInputHandler() {}
    using InputStream = std::istringstream;

signals:
    void userInputReceived(const QString& input);

public slots:
    void getInput(const QString& userInput)
    {
        qDebug() << "User input received: " << userInput;
        emit userInputReceived(userInput);
    }
};

#endif // USERINPUTHANDLER_H
