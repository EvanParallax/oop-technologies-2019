#ifndef GRAPHDBHELPER_H
#define GRAPHDBHELPER_H

#include "data/graph.h"
#include <QtSql>

class GraphDbHelper
{
public:
    GraphDbHelper();
    Graph* Read();
    void Write(Graph *graph);
};

#endif // GRAPHDBHELPER_H
