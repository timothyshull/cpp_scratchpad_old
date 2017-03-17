//
// Created by Timothy Shull on 12/5/15.
//

#ifndef CODINGINTERVIEW_LISTELEMENT_H
#define CODINGINTERVIEW_LISTELEMENT_H

template<typename T>
class ListElement {
    ListElement *next;
    T data;

public:
    ListElement(const T &value) : next{nullptr}, data{value} { }

    ~ListElement() { }

    ListElement *getNext() const { return next; }

    const T &value() const { return data; }

    void setNext(ListElement *elem) { next = elem; }

    void setValue(const T &value) { data = value; }

    int getValue() { return data; }

};

#endif //CODINGINTERVIEW_LISTELEMENT_H