#ifndef COMMANDLINEINPUTBOX_H
#define COMMANDLINEINPUTBOX_H

#include <QLayout>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>


class CommandLineInputBox : public QWidget
{
    Q_OBJECT

public:
    CommandLineInputBox();
    QLineEdit* getInputBox() const;
    QPushButton* getSubmitButton() const;
    QVBoxLayout* createInputBoxLayout();
    CommandLineInputBox& operator=(const CommandLineInputBox& other);
    CommandLineInputBox(const CommandLineInputBox& other);

signals:
    void userInputReceived(const QString& input);

public slots:
    void onSubmitClicked();

private:
    void createInputBox();
    void createSublitButton();

private:
    QLineEdit *inputBox;
    QPushButton* submitButton;
    QVBoxLayout* layout;

};

#endif // COMMANDLINEINPUTBOX_H
