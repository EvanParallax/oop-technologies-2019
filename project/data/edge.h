#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"


class Edge
{
    Vertex *from;
    Vertex *to;

public:
    QString graphName;
    Edge(Vertex *from, Vertex *to, QString graph) : from(from), to(to), graphName(graph) {}

    Vertex *getFrom() {return from;}
    Vertex *getTo() {return to;}
};

#endif // EDGE_H
