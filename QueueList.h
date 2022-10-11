#pragma once
#include <iostream>
#include "List.h"
using namespace std;

template <class T>
struct Element {
    T data; // данные
    Element<T> *Next;
    Element<T> *Prev;
};

template<class T>
class QueueList {
    Element<T>* Head;
    Element<T>* Tail;
    List<T> Wait;
    int Count;
    
public:
    QueueList() {
        Head = Tail = NULL;
        Count = 0;
    }

    QueueList(const QueueList& obj);

    Element<T> Extract(const QueueList& obj) {
        Head = Tail = NULL;
        Count = 0;
 
        Element<T>* temp = obj.Head;
        while (temp != 0) {
            AddTail(temp->data);
            temp = temp->next;
        }
    }

    void AddTail(T& x) {
        Element<T>* temp = new Element<T>;
        temp->Prev = 0;
        temp->data = x;
        temp->Next = Head;

        if (Head != 0) {  // Если элементы есть?
            Head->Prev = temp;
        }

        if (Count == 0) { // Если элемент первый, то он одновременно и голова и хвост
            Head = Tail = temp;
        }
        else {
            // иначе новый элемент - головной
            Head = temp;
        }
        Count++;
    }

    bool IsEmpty() {
        if (Head == NULL && Tail == NULL) {
            return "List is empty!";
        }
        else {
            return false;
        }
    }

    void Print() {
        Wait.Print();
    }

    int GetCount() {
        return Wait.GetCount();
    }

    T GetFirst() {
        return Wait.Head();
    }

};


