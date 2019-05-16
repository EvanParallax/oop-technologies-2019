#ifndef VERTEX_H
#define VERTEX_H

#include <QString>


class Vertex
{
public:
    Vertex(QString name, QString graph, QString desc): displayName(name), GraphName(graph), Description(desc) {}
    bool isVisited = false;
    const QString displayName;
    QString GraphName;
    QString Description;

};

#endif // VERTEX_H
