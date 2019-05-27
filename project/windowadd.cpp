#include "windowadd.h"
#include "ui_windowadd.h"

WindowAdd::WindowAdd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowAdd)
{
    ui->setupUi(this);
}

WindowAdd::~WindowAdd()
{
    delete ui;
}

void WindowAdd::on_AddVertexBut_clicked()
{
    QString s = ui->VertexEdit->text();
    emit VertexAdded(new Vertex(s,"",""));
}

void WindowAdd::on_pushButton_clicked()
{
    Vertex *from = new Vertex(ui->FromEdit->text(),"","");
    Vertex *to = new Vertex(ui->ToEdit->text(),"","");
    emit EdgeAdded(new Edge(from,to,""));
}
