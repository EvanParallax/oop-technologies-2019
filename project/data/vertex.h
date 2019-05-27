#ifndef VERTEX_H
#define VERTEX_H

#include <QString>


class Vertex
{
public:
    Vertex(){}
    Vertex(QString name,QString graph, QString cont): displayName(name), graphName(graph), content(cont) {}
    bool isVisited = false;
    QString displayName;
    QString graphName;
    QString content;

};

#endif // VERTEX_H
