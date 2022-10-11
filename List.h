#pragma once
#include <iostream>
using namespace std;

template<class T>
struct Elem {
    int data; // данные
    Elem* next, * prev;
};

template<class T>
class List {
    Elem<T>* Head, * Tail;
    int Count;

public:
    List();
    List(const List&);
    ~List();

    int GetCount();
    Elem<T>* GetElem(int);
    void DelAll();
    void Del(int pos = 0);
    void Insert(int pos = 0);
    void AddTail(int n);
    void AddHead(int n);
    void Print();
    void Print(int pos);

    List& operator = (const List&);
    // сложение двух списков (дописывание)
    List operator + (const List&);

    // переворачивание списка
    List operator - ();
};

template<class T>
List<T>::List()
{
    // Изначально список пуст
    Head = Tail = NULL;
    Count = 0;
}

template<class T>
List<T>::List(const List& L)
{
    Head = Tail = NULL;
    Count = 0;

    // Голова списка, из которого копируем
    Elem* temp = L.Head;
    // Пока не конец списка
    while (temp != 0)
    {
        // Передираем данные
        AddTail(temp->data);
        temp = temp->next;
    }
}

template<class T>
List<T>::~List()
{
    // Удаляем все элементы
    DelAll();
}

template<class T>
void List<T>::AddHead(int n)
{
    Elem<T>* temp = new Elem<T>;
    temp->prev = 0;
    temp->data = n;
    temp->next = Head;
    if (Head != 0)
    {
        Head->prev = temp;
    }
    if (Count == 0)
    {
        Head = Tail = temp;
    }
    else
    {
        Head = temp;
    }
    Count++;
}

template<class T>
void List<T>::AddTail(int n)
{
    Elem<T>* temp = new Elem<T>;
    temp->next = 0;
    temp->data = n;
    temp->prev = Tail;
    if (Tail != 0)
    {
        Tail->next = temp;
    }
    if (Count == 0)
    {
        Head = Tail = temp;
    }
    else
    {
        Tail = temp;
    }
    Count++;
}

template<class T>
void List<T>::Insert(int pos)
{
    if (pos == 0)
    {
        cin >> pos;
    }
    if (pos < 1 || pos > Count + 1)
    {
        return;
    }
    if (pos == Count + 1)
    {
        int data;
        cin >> data;
        AddTail(data);
        return;
    }
    else if (pos == 1)
    {
        int data;
        cin >> data;
        AddHead(data);
        return;
    }
    int i = 1;
    Elem<T>* Ins = Head;
    while (i < pos)
    {
        Ins = Ins->next;
        i++;
    }
    Elem<T>* PrevIns = Ins->prev;
    Elem<T>* temp = new Elem<T>;
    cin >> temp->data;
    if (PrevIns != 0 && Count != 1)
    {
        PrevIns->next = temp;
    }
    temp->next = Ins;
    temp->prev = PrevIns;
    Ins->prev = temp;
    Count++;
}

template<class T>
void List<T>::Del(int pos)
{
    if (pos == 0)
    {
        cin >> pos;
    }
    if (pos < 1 || pos > Count)
    {
        return;
    }
    Elem<T>* Del = nullptr;
    int i = 1;
    if (pos <= Count / 2)
    {
        Del = Head;
        while (i < pos)
        {
            Del = Del->next;
            i++;
        }
    }
    else
    {
        Del = Tail;
        while (i <= Count - pos)
        {
            Del = Del->prev;
            i++;
        }
    }
    Elem<T>* PrevDel = Del->prev;
    Elem<T>* AfterDel = Del->next;
    if (PrevDel != 0 && Count != 1)
    {
        PrevDel->next = AfterDel;
    }
    if (AfterDel != 0 && Count != 1)
    {
        AfterDel->prev = PrevDel;
    }
    if (pos == 1)
    {
        Head = AfterDel;
    }
    if (pos == Count)
    {
        Tail = PrevDel;
    }
    delete Del;
    Count--;
}

template<class T>
void List<T>::Print(int pos)
{
    // Позиция от 1 до Count?
    if (pos < 1 || pos > Count)
    {
        // Неверная позиция
        cout << "Incorrect position !!!\n";
        return;
    }

    Elem* temp;

    // Определяем с какой стороны 
    // быстрее двигаться
    if (pos <= Count / 2)
    {
        // Отсчет с головы
        temp = Head;
        int i = 1;

        while (i < pos)
        {
            // Двигаемся до нужного элемента
            temp = temp->next;
            i++;
        }
    }
    else
    {
        // Отсчет с хвоста
        temp = Tail;
        int i = 1;

        while (i <= Count - pos)
        {
            // Двигаемся до нужного элемента
            temp = temp->prev;
            i++;
        }
    }
    // Вывод элемента
    cout << pos << " element: ";
    cout << temp->data << endl;
}

template<class T>
void List<T>::Print() {
    if (Count != 0)
    {
        Elem<T>* temp = Head;
        cout << "\n";
        while (temp->next != 0)
        {
            cout << temp->data << "\n";
            temp = temp->next;
        }
        cout << temp->data << "\n";
    }
}

template<class T>
void List<T>::DelAll()
{
    // Пока остаются элементы, удаляем по одному с головы
    while (Count != 0)
        Del(1);
}

template<class T>
int List<T>::GetCount()
{
    return Count;
}
/// <summary>

template<class T>
Elem<T>* List<T>::GetElem(int pos)
{
    Elem* temp = nullptr;
    // Счетчик
    int i = 1;

    // Определяем с какой стороны 
    // быстрее двигаться
    if (pos <= Count / 2)
    {
        // Отсчет с головы
        temp = Head;

        while (i < pos)
        {
            // Двигаемся до нужного элемента
            temp = temp->next;
            i++;
        }
    }
    else
    {
        // Отсчет с хвоста
        temp = Tail;
        while (i <= Count - pos)
        {
            // Двигаемся до нужного элемента
            temp = temp->prev;
            i++;
        }
    }
    /////---------------------------------------------

    // Позиция от 1 до Count?
    if (pos < 1 || pos > Count)
    {
        // Неверная позиция
        cout << "Incorrect position !!!\n";
        return 0;
    }

    return temp;
}

template<class T>
List<T>& List<T>::operator = (const List& L)
{
    // Проверка присваивания элемента "самому себе"
    if (this == &L)
        return *this;

    // удаление старого списка
    this->~List(); // DelAll();

    Elem* temp = L.Head;

    // Копируем элементы
    while (temp != 0)
    {
        AddTail(temp->data);
        temp = temp->next;
    }

    return *this;
}

// сложение двух списков
template<class T>
List<T> List<T>::operator + (const List<T>& L)
{
    // Заносим во временный список элементы первого списка
    List Result(*this);
    // List Result = *this;

    Elem* temp = L.Head;

    // Добавляем во временный список элементы второго списка
    while (temp != 0)
    {
        Result.AddTail(temp->data);
        temp = temp->next;
    }

    return Result;
}

// переворот
template<class T>
List<T> List<T>::operator - () // 1 2 3 4 5
{
    List Result;

    Elem* temp = Head;
    // Копируем элементы списка, начиная с головного,
    // в свой путем добавления элементов в голову,
    // таким образом временный список Result будет содержать
    // элементы в обратном порядке
    while (temp != 0)
    {
        Result.AddHead(temp->data);// 5 4 3 2 1
        temp = temp->next;
    }

    return Result;
}