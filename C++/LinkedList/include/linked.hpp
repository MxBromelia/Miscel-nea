#ifndef LINKED_H
#define LINKED_H

#include<iostream>

template<typename T>
struct node{
    T value;
    struct node *next;
    struct node *prev;

    node(const T & value) {
        this->value = value;

        next = nullptr;
        prev = nullptr;
    }

    node(const T && value) {
        this->value = value;

        next = nullptr;
        prev = nullptr;
    }

    template<typename U>
    friend std::ostream& operator<<(std::ostream &, node<U>&);
};

template<typename T>
std::ostream& operator<<(std::ostream & stream, node<T> & out) {
    stream << out.value;
    return stream;
}

template<typename T>
class LinkedList {
    struct node<T> *list;
    int size;

public:
    LinkedList() {
        list = nullptr;
        size = 0;
    }

    void insert(const T &&value, int pos) {
        struct node<T> **ptr = &list;
        struct node<T> *ins = new struct node<T>(value);

        if(size==0) {
            list = ins;
            ins->next = ins;
            ins->prev = ins;
        } else if(pos == 0) {
            ins->next = list;
            list = ins;
        }
        size++;
    }

    template<typename U>
    friend std::ostream& operator<<(std::ostream&, LinkedList<U>&);
};

template<typename U>
std::ostream& operator<<(std::ostream & stream, LinkedList<U> & out) {
    struct node<U> *l = out.list;
    for(int i=0;i<out.size;i++)
        stream << *l << " -> ";
    stream << "end";

    return stream;
}

#endif