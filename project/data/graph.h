#ifndef GRAPH_H
#define GRAPH_H

#include "list.h"
#include "vertex.h"
#include "edge.h"
#include "queue.h"
#include "stack.h"

class Graph
{
    List<Vertex> *vertices = new List<Vertex>();
    List<Edge> *edges = new List<Edge>();

    void resetVertices() {
        for (Vertex *v : *vertices) {
            v->isVisited = false;
        }
        for (Edge *e : *edges) {
            e->getFrom()->isVisited = false;
            e->getTo()->isVisited = false;
        }
    }

public:
    QString graphName;
    Graph(){ }
    Graph(QString name) {graphName = name; }
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
        for (Vertex *v : *vertices) {
            if (v->displayName == name) {
                return v;
            }
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

        for (Edge *ed : *edges) {
            if (ed->getFrom() == from && ed->getTo() == to) {
                return true;
            }
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
        bool isEnd = edges->isEmpty();
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

    void removeEdge(QString from, QString to) {
        bool isEnd = edges->isEmpty();
        edges->toStart();
        while (!isEnd) {
            Edge *curr = edges->get();
            if (curr->getFrom()->displayName == from && curr->getTo()->displayName == to) {
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
        bool isEnd = edges->isEmpty();
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
        isEnd = vertices->isEmpty();
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

    void removeVertex(QString v) {
        bool isEnd = edges->isEmpty();
        edges->toStart();
        while (!isEnd) {
            Edge *curr = edges->get();
            if (curr->getFrom()->displayName == v || curr->getTo()->displayName == v) {
                edges->deleteCurr();
                edges->prev();
            }
            isEnd = edges->isEnd();
            edges->next();
        }

        vertices->toStart();
        isEnd = vertices->isEmpty();
        while (!isEnd) {
            Vertex *curr = vertices->get();
            if (curr->displayName == v) {
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

             bool isEnd = edges->isEmpty();
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

            bool isEnd = edges->isEmpty();
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


    List<Vertex> *getLearningOrder(Vertex *finalTopic) {

        resetVertices();
        List<Vertex> *list = new List<Vertex>();

        Vertex *final = findVertex(finalTopic->displayName);

        list->addBefore(final);
        final->isVisited = true;

        for (Edge *e : *edges) {
            if (e->getTo()->displayName == final->displayName) {
                e->getTo()->isVisited = true;
            }
            if (e->getFrom()->displayName == final->displayName) {
                e->getFrom()->isVisited = true;
            }
        }

        bool is_end = false;
        while (!is_end) {
            is_end = true;

            for (Edge *e : *edges) {
                if (e->getTo()->isVisited && !e->getFrom()->isVisited) {

                    Vertex *curr = findVertex(e->getFrom()->displayName);
                    list->addAfter(curr);

                    e->getFrom()->isVisited = true;
                    curr->isVisited = true;

                    is_end = false;
                }
            }
        }

        resetVertices();

        return list;
    }

};

#endif // GRAPH_H
