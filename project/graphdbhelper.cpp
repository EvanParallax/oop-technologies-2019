#include "graphdbhelper.h"
#include <QMessageBox>

GraphDbHelper::GraphDbHelper()
{

}

QList<Graph*>* GraphDbHelper::Read()
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("graph.db");

    if (!sdb.open())
    {
           qDebug() << sdb.lastError().text();
    }
    QList<Graph*>* g = new QList<Graph*>();
    QSqlQuery queryGraph("SELECT Name FROM Graphs");
    while (queryGraph.next()) {
             QString name = queryGraph.value(0).toString();
             QMessageBox b;
             b.setText(name);
             b.show();
             g->push_back(new Graph(name));
    }

    QSqlQuery queryVert("SELECT * FROM Vertices");
    while (queryVert.next()) {
             QString name = queryGraph.value(1).toString();
             for(Graph* var : *g)
             {
                if(var->name == name)
                    var->addVertex(new Vertex(queryGraph.value(0).toString(), queryGraph.value(1).toString(), queryGraph.value(2).toString()));
             }
    }

    QSqlQuery queryEdge("SELECT * FROM Edges");
    while (queryEdge.next()) {
             QString from = queryEdge.value(0).toString();
             QString to = queryEdge.value(1).toString();
             QString graphName = queryEdge.value(2).toString();
             Vertex *fromv = new Vertex(from,"","");
             Vertex *tov = new Vertex(to,"","");
             for(Graph* var : *g)
             {
                if(var->name == graphName)
                    var->addEdge(new Edge(fromv, tov, graphName));
             }
    }
    sdb.close();
    return g;
}

void GraphDbHelper::Write(QList<Graph*> *graph)
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("graph.db");

    if (!sdb.open())
    {
           qDebug() << sdb.lastError().text();
    }

    QSqlQuery queryGraph("DELETE FROM Graphs");
    QSqlQuery queryEdge("DELETE FROM Edges");
    QSqlQuery queryVert("DELETE FROM Vertices");

    for(Graph* var : *graph)
    {
        QSqlQuery graphQuery;
        graphQuery.prepare(
                  QString("INSERT INTO Graphs (Name) VALUES (%1);")
                                  .arg(var->name)
                  );
        graphQuery.exec();
        /*
        for(Vertex* item : var->getVertices())
        {
            QSqlQuery vertQuery;
            vertQuery.prepare(
                      QString("INSERT INTO Vertices (Name, GraphName, Description) VALUES (%1, %2, %3);")
                                      .arg(item->displayName).arg(item->GraphName).arg(item->Description)
                      );
            vertQuery.exec();
        }

        for(Edge* item : var->getEdges())
        {
            QSqlQuery edgeQuery;
            edgeQuery.prepare(
                      QString("INSERT INTO Edges (From, To, GraphName) VALUES (%1, %2, %3);")
                                      .arg(item->from->displayName).arg(item->to->displayName).arg(item->graph)
                      );
            edgeQuery.exec();
        }
        */
    }
}
