#ifndef LIST_H
#define LIST_H

#include "node.h"

template<typename T>
class ListIterator;


template<typename T>
class List {
    Node<T> *curr;
    Node<T> *first;
    Node<T> *last;

public:
    T *value;

    List(T *v = nullptr) : curr(nullptr), first(nullptr), last(nullptr), value(v) {}
    ~List() {
        curr = first;
        while (curr != last) {
            curr = curr->next;
            delete curr->prev;
        }
        delete curr;
        curr = first = last = nullptr;
    }

    // ... node1 -> curr -> node2 ...
    // results in
    // ... node1 -> NEW -> curr -> node2 ...
    List *addBefore(T *value) {
        Node<T> *node = new Node<T>(value);
        if (curr == nullptr) {
            curr = first = last = node;
        }
        else if (curr == first) {
            first = node;
            node->next = curr;
            curr->prev = node;
        }
        else {
            node->next = curr;
            node->prev = curr->prev;
            curr->prev->next = node;
            curr->prev = node;
        }
        return this;
    }

    // ... node1 -> curr -> node2 ...
    // results in
    // ... node1 -> curr -> NEW -> node2 ...
    List *addAfter(T *value) {
        Node<T> *node = new Node<T>(value);
        if (curr == nullptr) {
            curr = first = last = node;
        }
        else if (curr == last) {
            last = node;
            node->prev = curr;
            curr->next = node;
        }
        else {
            node->prev = curr;
            node->next = curr->next->next;
            curr->next->prev = node;
            curr->next = node;
        }
        return this;
    }

    List *deleteBefore() {
        if (curr == nullptr) {
            return this;
        }
        else if (curr == first) {
            curr = curr->next;
            curr->prev = nullptr;
            delete first;
            first = curr;
        }
        else if(curr->prev == first){
            curr->prev = nullptr;
            delete first;
            first = curr;
        }
        else {
            Node<T> *node = curr->prev;
            node->prev->next = curr;
            curr->prev = node->prev;
            delete node;
        }
        return this;
    }

    List *deleteAfter() {
        if (curr == nullptr) {
            return this;
        }
        else if (curr == last) {
            curr = curr->prev;
            delete curr->next;
            curr->next = nullptr;
            last = curr;
        }
        else if (curr->next == last) {
            delete curr->next;
            curr->next = nullptr;
            last = curr;
        }
        else {
            Node<T> *node = curr->next;
            curr->next = node->next;
            node->next->prev = curr;
            delete node;
        }
        return this;
    }

    List *deleteCurr() {
        if (curr == nullptr) {
            return this;
        }
        if (isStart() && isEnd()) {
            delete curr;
            curr = first = last = nullptr;
        }
        else if (isStart()) {
            next();
            deleteBefore();
        }
        else if (isEnd()) {
            prev();
            deleteAfter();
        }
        else {
            prev();
            deleteAfter();
        }
        return this;
    }

    List *next() {
        if (curr != last) {
            curr = curr->next;
        }
        return this;
    }

    Node<T> *getStart() {
        return first;
    }

    List *prev() {
        if (curr != first) {
            curr = curr->prev;
        }
        return this;
    }

    T *get() {
        return curr->value;
    }

    void toStart() {
        curr = first;
    }

    void toEnd() {
        curr = last;
    }

    bool hasNext() {
        return curr->next == nullptr;
    }

    bool isEnd() {
        return curr == last;
    }

    bool isStart() {
        return curr == first;
    }

    bool isEmpty() {
        return first == nullptr && last == nullptr;
    }

    bool find(T *value) {
        if (isEmpty()) {
            return false;
        }
        toStart();
        while (curr != last) {
            if (curr->value == value) {
                return true;
            }
            curr = curr->next;
        }
        if (curr->value == value) {
            return true;
        }
        else {
            return false;
        }
    }

    ListIterator<T> begin() {
        return ListIterator<T>(first);
    }

    ListIterator<T> end() {
        return ListIterator<T>(nullptr);
    }

};


template<typename T>
class ListIterator
{
public:
    ListIterator(Node<T> *curr) {
        this->curr = curr;
    }

    bool operator!=(ListIterator<T> &other)  {
        return other.curr != curr;
    }

    bool operator==(ListIterator<T> &other)  {
        return other.curr == curr;
    }

    T* operator*() {
        return curr->value;
    }

    ListIterator<T>& operator++() {
        curr = curr->next;
        return *this;
    }

private:
    Node<T> *curr;
};
#endif // LIST_H
