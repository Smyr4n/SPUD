#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Model needs to be initialized after UI
    model = new Model(ui->canvas, ui->toolbar);

    setupConnections();
}

MainWindow::~MainWindow()
{
    delete model;
    delete ui;
}

void MainWindow::setupConnections()
{
    connect(ui->toolbar, &Toolbar::addClass, ui->canvas, &Canvas::addClass);
}
