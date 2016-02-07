#ifndef STACKARRAY_H
#define STACKARRAY_H

//*array based stack
//map--base class using linked list with data field type void, inherit that and dereference void
//	bring .h and .o, reinherit so just using data field


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

using std::ostream;
using std::istream;
using std::cin;
using std::cout;
using std::endl;

enum STACK_ERRORS {STACK_EMPTY, STACK_FULL, INVALID_MAXSIZE};

template<typename T>
class stackArray
{
public:
    stackArray(size_t maxSize =  10);
    ~stackArray();
    stackArray(const stackArray<T> &other);
    stackArray<T>& operator=(const stackArray<T> &other);

    size_t size();
    size_t max_size();

    bool empty();
    bool full();
    void clear();
    void resize(size_t newSize);

    void push(const T &data);
    T pop();
    T top();

    stackArray<T>& operator<<(const T &data); //Chainable push
    stackArray<T>& operator>>(T &data); // Chainable pop

    template<typename R>
    friend ostream& operator<<(ostream& out, stackArray<R>& s);

    template<typename R>
    friend istream& operator>>(istream& in, stackArray<R>& s);

private:
    T *t;
    size_t qty, max_qty;

    void copy(const stackArray<T> &other);
    void nukem();
};

// initializing dynamic array
template<typename T>
stackArray<T>::stackArray(size_t maxSize)
{
    if(maxSize < 2)
        throw INVALID_MAXSIZE;
    qty = 0;
    max_qty = maxSize;

    // initializing dynamic array to 11, the extra spot is for??
    t = new T[maxSize + 1];
}

template<typename T>
stackArray<T>::~stackArray()
{
    nukem();
    max_qty = 0;
}

template<typename T>
stackArray<T>::stackArray(const stackArray<T> &other)
{
    copy(other);
}

template<typename T>
stackArray<T>& stackArray<T>::operator=(const stackArray<T> &other)
{
    if(this != &other)
    {
        nukem();
        copy(other);
    }
    return *this;
}


template<typename T>
size_t stackArray<T>::size()
{
    return qty;
}

template<typename T>
size_t stackArray<T>::max_size()
{
    return max_qty;
}


template<typename T>
bool stackArray<T>::empty()
{
    return !qty;
}

template<typename T>
bool stackArray<T>::full()
{
    return max_qty == qty;
}

template<typename T>
void stackArray<T>::clear()
{
    nukem();
}

template<typename T>
void stackArray<T>::resize(size_t newSize)
{
    nukem();
    if(newSize < 2)
        throw INVALID_MAXSIZE;
    max_qty = newSize;

    t = new T[max_qty];
}

template<typename T>
void stackArray<T>::push(const T &data)
{
    if(full())
        throw STACK_FULL;

    // insert "node"
    // top of stack is now the quantity
    ++qty;
    t[qty] = data;
}

// popping
template<typename T>
T stackArray<T>::pop()
{
    if(empty())
        throw STACK_EMPTY;

    // setting this data
    T data = t[qty];

    // "delete"/erase top of stack
    t[qty] = T();
    --qty;

    return data;
}

template<typename T>
T stackArray<T>::top()
{
    return t[qty];
}


template<typename T>
stackArray<T>& stackArray<T>::operator<<(const T &data) //Chainable push
{
    push(data);
    return *this;
}

template<typename T>
stackArray<T>& stackArray<T>::operator>>(T &data) // Chainable pop
{
    data = pop();
    return *this;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// private function
template<typename T>
void stackArray<T>::copy(const stackArray<T> &other)
{
    //    node<T> *ptr2, *ptr = other.nextNode();
    //    ptr2 = tos = new node<T>(*other.tos);

    if (this != &other)
    {
        this->nukem();

        qty = other.qty;
        max_qty = other.max_qty;

        for(size_t i = 1; i < max_size + 1; ++i)
        {
            t[i] = other.t[i];
        }

    }

    //    while(ptr)
    //    {
    //        ptr2->nextNode() = new node<T>(*ptr);
    //        ptr = ptr->nextNode();
    //        ptr2 = ptr2->nextNode();
    //    }
    //    qty = other.qty;
    //    max_qty = other.max_qty;
}

template<typename T>
void stackArray<T>::nukem()
{
    while(qty)
    {
        t[qty] = T();
        --qty;
    }

    delete [] t;
    t = NULL;
}

// pushing objects into this
template<typename R>
ostream& operator<<(ostream& out, stackArray<R>& s)
{

    if (out == cout)
    {
        for(size_t i = s.size(); i > 0; --i)
        {
            cout << s.t[i] << endl;
        }
    }
//    else
//    {
//        R r;
//    //            cout << "Data: ";

//        in >> r;

//        s.push(r);

//    }


    return out;
}

template<typename R>
istream& operator>>(istream& in, stackArray<R>& s)
{

//    cout << ">> \n";

    if (&cin == &in && !s.full())
    {
        R r;

        cout << "Data: ";

        in >> r;

        s.push(r);
    }


    //    if (&in == &cin)
    //    {


    // check the data type


    //    }
    //    if(!s.full())
    //    {
    //        in >> s.push();
    //    }

    //    node<R> newNode;
    //    while(in>>newNode)
    //        s<<;
    return in;
}








#endif // STACKARRAY_H
