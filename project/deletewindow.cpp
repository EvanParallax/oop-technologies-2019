#include "deletewindow.h"
#include "ui_deletewindow.h"

DeleteWindow::DeleteWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteWindow)
{
    ui->setupUi(this);
}

DeleteWindow::~DeleteWindow()
{
    delete ui;
}

void DeleteWindow::on_VertexDel_clicked()
{
    QString s = ui->VertexEdit->text();
    auto vert = new Vertex(s,"","");
    emit VertexDeleted(vert);
}

void DeleteWindow::on_EdgeDel_clicked()
{
    Vertex *from = new Vertex(ui->FromEdit->text(),"","");
    Vertex *to = new Vertex(ui->ToEdit->text(),"","");
    emit EdgeDeleted(new Edge(from,to, ""));
}
