#ifndef GRAPH_H
#define GRAPH_H

#include "list.h"
#include "vertex.h"
#include "edge.h"
#include "queue.h"
#include "stack.h"
#include <QString>

class Graph
{
    List<Vertex> *vertices = new List<Vertex>();
    List<Edge> *edges = new List<Edge>();


    void resetVertices() {
        bool isEnd = false;
        vertices->toStart();
        while (!isEnd) {
            Vertex *curr = vertices->get();
            curr->isVisited = false;
            isEnd = vertices->isEnd();
            vertices->next();
        }
    }

public:
    QString name;

    Graph(QString name)
    {
        this->name = name;
    }

    ~Graph() {
        delete vertices;
        delete edges;
    }

    List<Vertex> *getVertices() {
        return vertices;
    }

    List<Edge> *getEdges() {
        return edges;
    }

    Vertex *findVertex(QString name) {
        vertices->toStart();
        bool isEnd = false;
        while (!isEnd && !vertices->isEmpty()) {

            if (vertices->get()->displayName == name) {
                return vertices->get();
            }

            isEnd = vertices->isEnd();
            vertices->next();
        }

        return nullptr;
    }

    bool containsVertex(Vertex *v) {
        return vertices->find(v);
    }

    bool containsEdge(Edge *e) {
        bool isEmpty = edges->isEmpty();
        if (isEmpty) {
            return false;
        }
        Vertex *from = e->getFrom();
        Vertex *to = e->getTo();
        bool isEnd = false;
        edges->toStart();
        while (!isEnd) {
            Edge *curr = edges->get();
            if (curr->getFrom() == from && curr->getTo() == to) {
                return true;
            }
            isEnd = edges->isEnd();
            edges->next();
        }
        return false;
    }

    void addVertex(Vertex *v) {
        if (!containsVertex(v)) {
            vertices->addBefore(v);
        }
        else {
            throw;
        }
    }

    void addEdge(Edge *edge) {
        if (!containsEdge(edge)) {
            edges->addAfter(edge);
        }
        else {
            throw;
        }
    }

    void removeEdge(Edge *e) {
        Vertex *from = e->getFrom();
        Vertex *to = e->getTo();
        bool isEnd = false;
        edges->toStart();
        while (!isEnd) {
            Edge *curr = edges->get();
            if (curr->getFrom() == from && curr->getTo() == to) {
                edges->deleteCurr();
                return;
            }
            isEnd = edges->isEnd();
            edges->next();
        }
        throw;
    }

    void removeVertex(Vertex *v) {
        if (!containsVertex(v)) {
            throw;
        }
        bool isEnd = false;
        edges->toStart();
        while (!isEnd) {
            Edge *curr = edges->get();
            if (curr->getFrom() == v || curr->getTo() == v) {
                edges->deleteCurr();
                edges->prev();
            }
            isEnd = edges->isEnd();
            edges->next();
        }

        vertices->toStart();
        while (!isEnd) {
            Vertex *curr = vertices->get();
            if (curr == v) {
                vertices->deleteCurr();
                return;
            }
            isEnd = vertices->isEnd();
            vertices->next();
        }
        throw;
    }


    List<Vertex> *BFS(Vertex *v) {

        resetVertices();

        Queue<Vertex> *queue = new Queue<Vertex>();
        List<Vertex> *list = new List<Vertex>();

        v->isVisited = true;
        list->addAfter(v);
        queue->push(v);

        while (!queue->isEmpty()) {
             Vertex *currVertex = queue->pop();

             bool isEnd = false;
             edges->toStart();
             while (!isEnd) {
                 Edge *currEdge = edges->get();
                 if (currEdge->getFrom() == currVertex && !currEdge->getTo()->isVisited) {
                     Vertex *nextVertex = currEdge->getTo();
                     nextVertex->isVisited = true;
                     queue->push(nextVertex);
                     list->addAfter(nextVertex);
                 }
                 isEnd = edges->isEnd();
                 edges->next();
             }
        }

        delete queue;
        return list;
    }


    List<Vertex> *DFS(Vertex *v) {

        resetVertices();

        List<Vertex> *list = new List<Vertex>();
        Stack<Vertex> *stack = new Stack<Vertex>();

        v->isVisited = true;
        list->addAfter(v);

        Vertex *currVertex = v;

        while (true) {

            bool isDeeper = false;

            bool isEnd = false;
            edges->toStart();
            while (!isEnd) {
                Edge *currEdge = edges->get();
                if (currEdge->getFrom() == currVertex && !currEdge->getTo()->isVisited) {
                    currVertex = currEdge->getTo();
                    currVertex->isVisited = true;
                    list->addAfter(currVertex);
                    stack->push(currVertex);
                    isDeeper = true;
                    break;
                }
                isEnd = edges->isEnd();
                edges->next();
            }

            if (!isDeeper) {
                if (stack->isEmpty()) {
                    break;
                }
                else {
                    currVertex = stack->pop();
                }
            }
        }

        delete stack;
        return list;
    }

    bool isCyclic() {

        if (edges->isEmpty()) {
            return false;
        }

        return false;
    }

};

#endif // GRAPH_H
