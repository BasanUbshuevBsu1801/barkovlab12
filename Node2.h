#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Elem
{
    T data;
    Elem* next, * prev;
};

template <typename T>
class ListD
{
    Elem<T>* Head;
    Elem<T>* Tail;
    int Count;

public:
    ListD();
    ~ListD();
    int GetSize();
    void DelAll();
    T Del(int pos = 0);
    void PushBack(T n);
    void PushFront(T n);
    void PeekFront() const;
    void PeekBack() const;
    T PopFront();
    T PopBack();
    void Print();
    void Print(int pos);
    T sel_el(const int index) const;

    template <typename T>
    friend ostream& operator << (ostream& stream, const ListD&);
};

template <typename T>
ListD<T>::ListD()
{
    Head = Tail = NULL;
    Count = 0;
}

template <typename T>
ListD<T>::~ListD()
{
    DelAll();
}

template <typename T>
void ListD<T>::PushFront(T n)
{
    Elem<T>* temp = new Elem<T>;
    temp->prev = 0;
    temp->data = n;
    temp->next = Head;
    if (Head != 0)
        Head->prev = temp;
    if (Count == 0)
        Head = Tail = temp;
    else
        Head = temp;

    Count++;
}

template <typename T>
void ListD<T>::PushBack(T n)
{
    Elem<T>* temp = new Elem<T>;
    temp->next = 0;
    temp->data = n;
    temp->prev = Tail;

    if (Tail != 0)
        Tail->next = temp;

    if (Count == 0)
        Head = Tail = temp;
    else
        Tail = temp;

    Count++;
}

template <typename T>
T ListD<T>::Del(int pos)
{
    if (pos == 0)
    {
        cout << "Input position: ";
        cin >> pos;
    }
    if (pos < 1 || pos > Count)
    {
        cout << "Incorrect position !!!\n";
        return T();
    }

    int i = 1;

    Elem<T>* Del = Head;

    while (i < pos)
    {
        Del = Del->next;
        i++;
    }

    Elem<T>* PrevDel = Del->prev;
    Elem<T>* AfterDel = Del->next;

    if (PrevDel != 0 && Count != 1)
        PrevDel->next = AfterDel;
    if (AfterDel != 0 && Count != 1)
        AfterDel->prev = PrevDel;

    if (pos == 1)
        Head = AfterDel;
    if (pos == Count)
        Tail = PrevDel;

    T data = Del->data;

    delete Del;

    Count--;

    return data;
}

template <typename T>
void ListD<T>::Print(int pos)
{
    if (pos < 1 || pos > Count)
    {
        cout << "Incorrect position !!!\n";
        return;
    }

    Elem<T>* temp;

    if (pos <= Count / 2)
    {
        temp = Head;
        int i = 1;

        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
    }
    else
    {
        temp = Tail;
        int i = 1;

        while (i <= Count - pos)
        {
            temp = temp->prev;
            i++;
        }
    }
    cout << pos << " element: ";
    cout << temp->data << endl;
}

template <typename T>
void ListD<T>::Print()
{
    if (Count != 0)
    {
        Elem<T>* temp = Head;
        cout << "( ";
        while (temp->next != 0)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }

        cout << temp->data << " )\n";
    }
}

template <typename T>
void ListD<T>::DelAll()
{

    while (Count != 0)
        Del(1);
}

template <typename T>
int ListD<T>::GetSize()
{
    return Count;
}

template <typename T>
void ListD<T>::PeekFront() const
{
    Elem<T>* temp = Head;
    cout << temp->data << endl;
}

template <typename T>
void ListD<T>::PeekBack() const
{
    Elem<T>* temp = Tail;
    cout << temp->data << endl;
}

template <typename T>
T ListD<T>::PopFront()
{
    return Del(1);
}

template <typename T>
T ListD<T>::PopBack()
{
    return Del(9);
}

template<typename T>
T ListD<T>::sel_el(const int index) const
{
    int indexmax = Count - 1, indexmin = 0;
    indexmax -= index;
    indexmin += index;
    if (indexmin < indexmax || indexmin == indexmax)
    {
        int counter = 0;
        Elem<T>* current = Head;
        while (current != nullptr)
        {
            if (counter == index)
            {
                return current->data;
            }
            current = current->next;
            counter++;
        }
    }
    else if (indexmin > indexmax)
    {
        int counter = Count - 1; /
            Elem<T>*current = Tail;
        while (current != nullptr)
        {
            if (counter == index)
            {
                return current->data;
            }
            current = current->prev;
            counter--;
        }
    }
}

template <typename T>
std::ostream& operator << (std::ostream& stream, const ListD<T>& L)
{
    Elem<T>* temp = L.Head;
    while (temp != NULL)
    {
        stream << temp->data << "";
        temp = temp->next;
    }
    return stream << endl;
}
