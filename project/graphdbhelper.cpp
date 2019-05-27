#include "graphdbhelper.h"
#include <QMessageBox>
#include <QDebug>

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
    QSqlQuery queryGraph;
    queryGraph.exec("SELECT * FROM Graphs");
    while (queryGraph.next()) {
             QString name = queryGraph.value(0).toString();
             g->push_back(new Graph(name));
    }

    QSqlQuery queryVert;
    queryVert.exec("SELECT * FROM Vertices");
    while (queryVert.next())
    {
        QSqlRecord rec = queryVert.record();
             QString name = rec.value(1).toString();
             QString display = rec.value(0).toString();
             QString cont = rec.value(2).toString();
             for(Graph* var : *g)
             {
                if(var->graphName == name)
                    var->addVertex(new Vertex(display,name,cont));
             }
    }

    QSqlQuery queryEdge;
    queryEdge.exec("SELECT * FROM Edges");
    while (queryEdge.next()) {
             QString from = queryEdge.value(0).toString();
             QString to = queryEdge.value(1).toString();
             QString graphName = queryEdge.value(2).toString();
             Vertex *fromv = new Vertex(from,"","");
             Vertex *tov = new Vertex(to,"","");
             for(Graph* var : *g)
             {
                if(var->graphName == graphName)
                    var->addEdge(new Edge(fromv, tov, graphName));
             }
    }
    sdb.close();
    return g;
}

void GraphDbHelper::writeVert(Vertex *v)
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("graph.db");

    if (!sdb.open())
    {
           qDebug() << sdb.lastError().text();
    }

    QSqlQuery vertQuery;
    auto f = v->graphName;
    vertQuery.prepare(
              QString("INSERT INTO Vertices(Name,GraphName,Description) values(:Name,:GraphName,:Description);"));
    vertQuery.bindValue(":Name",v->displayName);
    vertQuery.bindValue(":GraphName",v->graphName);
    vertQuery.bindValue(":Description",v->graphName);
    qDebug() << vertQuery.exec() << endl;
    sdb.close();
}

void GraphDbHelper::writeEdge(Edge *e)
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("graph.db");

    if (!sdb.open())
    {
           qDebug() << sdb.lastError().text();
    }

    QSqlQuery edgeQuery;
    auto f = e->graphName;
    edgeQuery.prepare(
              QString("INSERT INTO Edges(FromEdge,ToEdge,GraphName) values(:FromEdge,:ToEdge,:GraphName);"));
    edgeQuery.bindValue(":FromEdge",e->getFrom()->displayName);
    edgeQuery.bindValue(":ToEdge",e->getTo()->displayName);
    edgeQuery.bindValue(":GraphName",e->graphName);
    qDebug() << edgeQuery.exec() << endl;
    sdb.close();
}

void GraphDbHelper::deleteVert(Graph *g, Vertex *v)
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("graph.db");

    if (!sdb.open())
    {
           qDebug() << sdb.lastError().text();
    }

    QSqlQuery query;

    query.prepare("DELETE FROM Vertices WHERE Name='" + v->displayName +
                  "' AND GraphName='" + v->graphName +"';");
    qDebug() << query.exec();

    for(auto item : *g->getEdges())
    {
        if(item->getFrom()->displayName == v->displayName)
        {
            QSqlQuery query;

            query.prepare("DELETE FROM Edges WHERE FromEdge='" + item->getFrom()->displayName +
                          "' AND GraphName='" + v->graphName +"';");
            qDebug() << query.exec();
        }

        if(item->getTo()->displayName == v->displayName)
        {
            QSqlQuery query;

            query.prepare("DELETE FROM Edges WHERE ToEdge='" + v->displayName +
                          "' AND GraphName='" + v->graphName +"';");

            qDebug() << query.exec();
        }
    }

    sdb.close();
}


void GraphDbHelper::deleteEdge(Edge *e)
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("graph.db");

    if (!sdb.open())
    {
           qDebug() << sdb.lastError().text();
    }

    QSqlQuery query;

    auto a = e->getFrom()->displayName;
    auto b  =e->getTo()->displayName  ;
    auto c =e->graphName;

    query.prepare("DELETE FROM Edges WHERE FromEdge='" + e->getFrom()->displayName +
                  "' AND ToEdge='" + e->getTo()->displayName +
                  "' AND GraphName='" + e->graphName +"';");
    qDebug() << query.exec();

    sdb.close();

}


