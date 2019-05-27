#include "window.h"
#include "ui_window.h"
#include <QFile>
#include <QTextStream>
#include <QSvgWidget>
#include <QBoxLayout>
#include "data/list.h"
#include "data/vertex.h"
#include "data/edge.h"
#include "data/graph.h"
#include "windowadd.h"
#include "graphdbhelper.h"

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    GraphDbHelper *helper = new GraphDbHelper();

    svgTree = new QSvgWidget();

    ui->layout->addWidget(svgTree);
    svgTree->resize(svgTree->sizeHint());


    graphs = helper->Read();

    for(auto item : *graphs)
    {
        auto var = item->graphName;
        ui->GoalBox->addItem(item->graphName);
    }



    if(graphs->isEmpty())
    {
        graph = new Graph();
        graphs->append(graph);
    }
    else
    {
        graph = graphs->first();
    }


    window = new WindowAdd(this);
    connect(window, SIGNAL(VertexAdded(Vertex*)),this,SLOT(onVertexAdded(Vertex*)));
    connect(window, SIGNAL(EdgeAdded(Edge*)),this,SLOT(onEdgeAdded(Edge*)));

    win = new DeleteWindow(this);
    connect(win, SIGNAL(VertexDeleted(Vertex*)),this,SLOT(onVertexDeleted(Vertex*)));
    connect(win, SIGNAL(EdgeDeleted(Edge*)),this,SLOT(onEdgeDeleted(Edge*)));

    onGraphChanged(graph);
}

Window::~Window()
{
    disconnect(window, SIGNAL(VertexAdded(Vertex*)),this,SLOT(onVertexAdded(Vertex*)));
    disconnect(window, SIGNAL(EdgeAdded(Edge*)),this,SLOT(onEdgeAdded(Edge*)));
    delete window;

    disconnect(win, SIGNAL(VertexDeleted(Vertex*)),this,SLOT(onVertexDeleted(Vertex*)));
    disconnect(win, SIGNAL(EdgeDeleted(Edge*)),this,SLOT(onEdgeDeleted(Edge*)));
    delete win;



    delete ui;
    delete graph;
}

void Window::onGraphChanged(Graph *graph)
{
    QFile file("graph.dot");

    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream( &file );
        stream << "digraph {\n";

        List<Vertex> *vertices = graph->getVertices();
        for (Vertex *v : *vertices) {
            stream << " \"" << v->displayName << "\";\n";
        }

        List<Edge> *edges = graph->getEdges();
        for (Edge *e : *edges) {
            Vertex *from = e->getFrom();
            Vertex *to = e->getTo();
            stream << " \"" << from->displayName << "\" -> \"" << to->displayName << "\";\n";
        }

        stream << "}\n";
    }

    file.close();

    QString command("dot -Tsvg graph.dot -o graph.svg");

    system(command.toStdString().c_str());

    svgTree->load((QString) "graph.svg");
    svgTree->resize(svgTree->sizeHint());
    svgTree->resize(svgTree->sizeHint());
}

void Window::onVertexAdded(Vertex *v)
{
    v->graphName = graph->graphName;
    graph->addVertex(v);
    onGraphChanged(graph);
    GraphDbHelper *helper = new GraphDbHelper();
    helper->writeVert(v);
    delete helper;

}

void Window::onEdgeAdded(Edge *e)
{
    e->graphName = graph->graphName;
    graph->addEdge(e);

    onGraphChanged(graph);

    GraphDbHelper *helper = new GraphDbHelper();
    helper->writeEdge(e);
    delete helper;
}

void Window::onVertexDeleted(Vertex *v)
{
    v->graphName = graph->graphName;
    GraphDbHelper *helper = new GraphDbHelper();
    helper->deleteVert(graph, v);
    delete helper;

    graph->removeVertex(v->displayName);
    onGraphChanged(graph);
}

void Window::onEdgeDeleted(Edge *e)
{
    e->graphName = graph->graphName;

    graph->removeEdge(e->getFrom()->displayName, e->getTo()->displayName);
    onGraphChanged(graph);
    GraphDbHelper *helper = new GraphDbHelper();
    helper->deleteEdge(e);
    delete helper;
}

void Window::on_addItem_clicked()
{
    window->show();
}

void Window::on_addEdge_clicked()
{

}

void Window::on_Remove_clicked()
{
    win->show();
}

void Window::on_GoalBox_currentTextChanged(const QString &arg1)
{
    for(auto item : *graphs)
    {
        if(item->graphName == ui->GoalBox->currentText())
           graph = item;
    }
    ui->ThemeBox->clear();
    for(auto item : *graph->getVertices())
        ui->ThemeBox->addItem(item->displayName);
    onGraphChanged(graph);
}

void Window::on_ThemeBox_currentTextChanged(const QString &arg1)
{
    for(auto item : *graph->getVertices())
    {
        if(item->displayName == ui->ThemeBox->currentText())
           ui->textBrowser->setText(item->content);
    }
}
