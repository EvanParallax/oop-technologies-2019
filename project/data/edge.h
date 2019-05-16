#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"


class Edge
{


public:
    Vertex *from;
    Vertex *to;

    Edge(Vertex *from, Vertex *to, QString g) : from(from), to(to), graph(g) {}

    QString graph;
    Vertex *getFrom() {return from;}
    Vertex *getTo() {return to;}
};

#endif // EDGE_H
