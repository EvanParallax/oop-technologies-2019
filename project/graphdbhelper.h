#ifndef GRAPHDBHELPER_H
#define GRAPHDBHELPER_H

#include "data/graph.h"
#include "data/list.h"
#include <QtSql>
#include <QList>

class GraphDbHelper
{
public:
    GraphDbHelper();
    QList<Graph*>* Read();

    void writeVert(Vertex *v);
    void writeEdge(Edge *e);
    void deleteEdge(Edge *e);
    void deleteVert(Graph *g, Vertex *v);
    void writeGraph(QString name);
    void deleteGraph(Graph * g);
};

#endif // GRAPHDBHELPER_H
