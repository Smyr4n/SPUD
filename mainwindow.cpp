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
    // Connect toolbar signals to canvas slots
    connect(ui->toolbar, &Toolbar::addClass, ui->canvas, &Canvas::addClass);
    connect(ui->toolbar, &Toolbar::addAbstractClass, ui->canvas, &Canvas::addAbstractClass);
    connect(ui->toolbar, &Toolbar::addInterface, ui->canvas, &Canvas::addInterface);
    connect(ui->toolbar, &Toolbar::addEnum, ui->canvas, &Canvas::addEnum);
}
