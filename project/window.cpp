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
#include <QList>

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    helper = new GraphDbHelper();

    graph = helper->Read();

    for(auto g : *graph){
        ui->GraphBox->addItem(g->name);
        currGraph = g;
        break;
    }
    //currGraph = graph->first();

    svgTree = new QSvgWidget();

    ui->layout->addWidget(svgTree);
    svgTree->resize(svgTree->sizeHint());

    onGraphChanged(currGraph);
}

Window::~Window()
{
    /*
    disconnect(window, SIGNAL(VertexAdded(Vertex*)),this,SLOT(onVertexAdded(Vertex*)));
    disconnect(window, SIGNAL(EdgeAdded(Edge*)),this,SLOT(onEdgeAdded(Edge*)));
    delete window;

    disconnect(win, SIGNAL(VertexDeleted(Vertex*)),this,SLOT(onVertexDeleted(Vertex*)));
    disconnect(win, SIGNAL(EdgeDeleted(Edge*)),this,SLOT(onEdgeDeleted(Edge*)));
    delete win;
*/
    delete ui;
    helper->Write(graph);
    delete graph;
}

void Window::onGraphChanged(Graph *graph)
{
    QFile file("graph.dot");

    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream( &file );
        stream << "digraph {\n";

        List<Vertex> *vertices = graph->getVertices();
        vertices->toStart();
        bool isEnd = false;
        while (!isEnd && !vertices->isEmpty()) {
            stream << " \"" << vertices->get()->displayName << "\";\n";
            isEnd = vertices->isEnd();
            vertices->next();
        }

        List<Edge> *edges = graph->getEdges();
        edges->toStart();
        isEnd = false;
        while (!isEnd && !edges->isEmpty()) {
            Vertex *from = edges->get()->getFrom();
            Vertex *to = edges->get()->getTo();
            stream << " \"" << from->displayName << "\" -> \"" << to->displayName << "\";\n";
            isEnd = edges->isEnd();
            edges->next();
        }

        stream << "}\n";
    }

    file.close();

    QString command("dot -Tsvg graph.dot -o graph.svg");

    system(command.toStdString().c_str());

    svgTree->load((QString) "graph.svg");
    svgTree->resize(svgTree->sizeHint());
}

void Window::onVertexAdded(Vertex *v)
{
    currGraph->addVertex(v);
    onGraphChanged(currGraph);
}

void Window::onEdgeAdded(Edge *e)
{
    currGraph->addEdge(e);
    onGraphChanged(currGraph);
}

void Window::onVertexDeleted(Vertex *v)
{
    currGraph->removeVertex(v);
    onGraphChanged(currGraph);
}

void Window::onEdgeDeleted(Edge *e)
{
    currGraph->removeEdge(e);
    onGraphChanged(currGraph);
}

void Window::on_addItem_clicked()
{
    WindowAdd* window = new WindowAdd(currGraph, this);
    connect(window, SIGNAL(VertexAdded(Vertex*)),this,SLOT(onVertexAdded(Vertex*)));
    connect(window, SIGNAL(EdgeAdded(Edge*)),this,SLOT(onEdgeAdded(Edge*)));
    window->show();
}

void Window::on_addEdge_clicked()
{

}

void Window::on_Remove_clicked()
{
    DeleteWindow* win = new DeleteWindow(currGraph, this);
    connect(win, SIGNAL(VertexDeleted(Vertex*)),this,SLOT(onVertexDeleted(Vertex*)));
    connect(win, SIGNAL(EdgeDeleted(Edge*)),this,SLOT(onEdgeDeleted(Edge*)));
    win->show();
}
