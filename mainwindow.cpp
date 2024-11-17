#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Model needs to be initialized after UI
    model = new Model(ui->canvas, ui->toolbar);
}

MainWindow::~MainWindow()
{
    delete model;
    delete ui;
}

