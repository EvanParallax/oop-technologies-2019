#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QSvgWidget>
#include "data/graph.h"
#include "windowadd.h"
#include "deletewindow.h"
#include "graphdbhelper.h"

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window();

private:
    Ui::Window *ui;

    GraphDbHelper *helper;
    QList<Graph*> *graph;
    Graph* currGraph;
    QSvgWidget *svgTree;

    void onGraphChanged(Graph *graph);
public slots:   
    void onVertexAdded(Vertex *v);
    void onEdgeAdded(Edge *e);

    void onVertexDeleted(Vertex *v);
    void onEdgeDeleted(Edge *e);
private slots:
    void on_addItem_clicked();
    void on_addEdge_clicked();
    void on_Remove_clicked();
};

#endif // WINDOW_H
