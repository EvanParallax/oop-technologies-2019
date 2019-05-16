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
    void Write(QList<Graph*> *graph);
};

#endif // GRAPHDBHELPER_H
