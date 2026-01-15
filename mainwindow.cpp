#include "mainwindow.h"

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    setupConnections();
}

void MainWindow::setupUI()
{
    auto *central = new QWidget(this);
    setCentralWidget(central);

    taskInput = new QLineEdit;
    taskInput->setPlaceholderText("Enter a task...");

    addButton = new QPushButton("Add");
    deleteButton = new QPushButton("Delete");

    taskList = new QListWidget;

    auto *topLayout = new QHBoxLayout;
    topLayout->addWidget(taskInput);
    topLayout->addWidget(addButton);

    auto *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(taskList);
    mainLayout->addWidget(deleteButton);

    central->setLayout(mainLayout);

    setWindowTitle("Task Manager");
    resize(420, 320);
}

void MainWindow::setupConnections()
{
    connect(addButton, &QPushButton::clicked,
            this, &MainWindow::onAddTask);

    connect(deleteButton, &QPushButton::clicked,
            this, &MainWindow::onDeleteTask);
}

void MainWindow::onAddTask()
{
    const QString task = taskInput->text().trimmed();

    if (!task.isEmpty()) {
        taskList->addItem(task);
        taskInput->clear();
    }
}

void MainWindow::onDeleteTask()
{
    delete taskList->currentItem();
}
