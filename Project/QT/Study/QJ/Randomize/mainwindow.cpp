#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QString str("ȷ��");
    btn = new QPushButton(str);
    str = "�������������";
    edit1 = new QLineEdit(str);
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(edit1);
    vbox->addWidget(btn);
    vbox->addWidget(edit2);
    this->setLayout(vbox);
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(btnclick()));
}

MainWindow::~MainWindow() {
}
