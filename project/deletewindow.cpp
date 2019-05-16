#include "deletewindow.h"
#include "ui_deletewindow.h"

DeleteWindow::DeleteWindow(Graph *g, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteWindow)
{
    ui->setupUi(this);
    graph = g;
}

DeleteWindow::~DeleteWindow()
{
    delete ui;
}

void DeleteWindow::on_VertexDel_clicked()
{
    QString s = ui->VertexEdit->text();
    emit VertexDeleted(new Vertex(s, graph->name,""));
}

void DeleteWindow::on_EdgeDel_clicked()
{
    Vertex *from = new Vertex(ui->FromEdit->text(),graph->name,"");
    Vertex *to = new Vertex(ui->ToEdit->text(), graph->name,"");
    emit EdgeDeleted(new Edge(from,to,graph->name));
}
