#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLineEdit;
class QPushButton;
class QListWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void onAddTask();
    void onDeleteTask();

private:
    void setupUI();
    void setupConnections();

    QLineEdit *taskInput;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QListWidget *taskList;
};

#endif
