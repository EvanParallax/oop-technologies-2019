#include "windowadd.h"
#include "ui_windowadd.h"

WindowAdd::WindowAdd(Graph* g, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowAdd)
{
    ui->setupUi(this);
    graph = g;
}

WindowAdd::~WindowAdd()
{
    delete ui;
}

void WindowAdd::on_AddVertexBut_clicked()
{
    QString s = ui->VertexEdit->text();

    emit VertexAdded(new Vertex(s, graph->name, ""));
}

void WindowAdd::on_pushButton_clicked()
{


    Vertex *from = new Vertex(ui->FromEdit->text(), graph->name, "");
    Vertex *to = new Vertex(ui->ToEdit->text(), graph->name, "");
    emit EdgeAdded(new Edge(from,to, graph->name));
}
