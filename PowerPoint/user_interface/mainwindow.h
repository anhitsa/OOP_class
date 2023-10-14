#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../input_handler/userinputhandler.h"
#include "../document/slide.h"

#include "ui_mainwindow.h"

#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static void exitApplication();

public:
    Ui::MainWindow *ui;
    QLineEdit *inputBox;
    QPushButton* submitButton;

signals:
    void userInputReceived(const QString& input);

public slots:
    void onSubmitClicked();

private:
    void createInputLayout(QVBoxLayout*);

};

#endif // MAINWINDOW_H
