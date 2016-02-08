#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include "node.h"

using std::ostream;
using std::istream;
using std::endl;

enum STACK_ERRORS {STACK_EMPTY, STACK_FULL, INVALID_MAXSIZE};

template<typename T>
class stack
{
    public:
        stack(unsigned int maxSize =  10);
        ~stack();
        stack(const stack<T> &other);
        stack<T>& operator=(const stack<T> &other);

        unsigned int size();
        unsigned int max_size();

        bool empty();
        bool full();
        void clear();
        void resize(unsigned int newSize);

        void push(const T &data);
        T pop();
        T top();

        stack<T>& operator<<(const T &data); //Chainable push
        stack<T>& operator>>(T &data); // Chainable pop

        template<typename R>
        friend
        ostream& operator<<(ostream& out, const stack<R> &s);

        template<typename R>
        friend
        istream& operator>>(istream& in, stack<R> &s);

    private:
        node<T>* tos;
        unsigned int qty, max_qty;

        void copy(const stack<T> &other);
        void nukem();
};
template<typename T>
stack<T>::stack(unsigned int maxSize)
{
    if(maxSize < 2)
        throw INVALID_MAXSIZE;
    tos = NULL;
    qty = 0;
    max_qty = maxSize;
}

template<typename T>
stack<T>::~stack()
{
    nukem();
    max_qty = 0;
}

template<typename T>
stack<T>::stack(const stack<T> &other)
{
    copy(other);
}

template<typename T>
stack<T>& stack<T>::operator=(const stack<T> &other)
{
    if(this != &other)
    {
        nukem();
        copy(other);
    }
    return *this;
}


template<typename T>
unsigned int stack<T>::size()
{
    return qty;
}

template<typename T>
unsigned int stack<T>::max_size()
{
    return max_qty;
}


template<typename T>
bool stack<T>::empty()
{
    return !tos;
}

template<typename T>
bool stack<T>::full()
{
    return max_qty == qty;
}

template<typename T>
void stack<T>::clear()
{
    nukem();
}

template<typename T>
void stack<T>::resize(unsigned int newSize)
{
    nukem();
    if(newSize < 2)
        throw INVALID_MAXSIZE;
    max_qty = newSize;
}

template<typename T>
void stack<T>::push(const T &data)
{
    if(full())
        throw STACK_FULL;
    ++qty;
    node<T>* newNode = new node<T>(data);
    newNode->nextNode() = tos;
    tos = newNode;
}

template<typename T>
T stack<T>::pop()
{
    if(empty())
        throw STACK_EMPTY;
    node<T> *bye = tos;
    T data = bye->getData();
    tos = tos->nextNode();
    delete bye;
    --qty;
    return data;
}

template<typename T>
T stack<T>::top()
{
    return tos->getData();
}


template<typename T>
stack<T>& stack<T>::operator<<(const T &data) //Chainable push
{
    push(data);
    return *this;
}

template<typename T>
stack<T>& stack<T>::operator>>(T &data) // Chainable pop
{
    data = pop();
    return *this;
}

template<typename T>
void stack<T>::copy(const stack<T> &other)
{
    node<T> *ptr2, *ptr = other.nextNode();
    ptr2 = tos = new node<T>(*other.tos);
    while(ptr)
    {
        ptr2->nextNode() = new node<T>(*ptr);
        ptr = ptr->nextNode();
        ptr2 = ptr2->nextNode();
    }
    qty = other.qty;
    max_qty = other.max_qty;
}

template<typename T>
void stack<T>::nukem()
{
    node<T> *ptr;
    qty = 0;
    while(tos)
    {
        ptr = tos;
        tos = tos->nextNode();
        delete ptr;
    }
}

template<typename R>
ostream& operator<<(ostream& out, const stack<R> &s)
{
    node<R> *ptr = s.tos;
    for(; ptr; ptr = ptr->nextNode()) // getting all the data in the stack
        out<<ptr->getData()<<endl; // streaming data into the out object
    return out;
}

template<typename R>
istream& operator>>(istream& in, stack<R> &s)
{
    node<R> newNode;

//    while(in>>newNode && !s.full()) // streaming in into newNode
    in >> newNode.data;
        s<<newNode.getData(); // streaming newNode data into object s
    return in; // getting object back to use it again (for chaining multiple objects cin >> a >> b >> c)
}

#endif // STACK_H
