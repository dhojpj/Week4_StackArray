#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

using std::ostream;
using std::istream;
using std::endl;

template<typename T>
class node
{
public:
    node(const T &d = T()) : data(d), ptr(NULL)
    {}

    ~node()
    {
        data = T();
        ptr = NULL;
    }

    node(const node<T> &d)
    {
        copy(d);
    }

    node<T>& operator=(const node<T> &other)
    {
        if(this != &other)
            copy(other);
        return *this;
    }

    void setData(const T& d)
    {\
        data = d;
    }

    T getData()
    {
        return data;
    }

    node<T>*& nextNode()
    {
        return ptr;
    }

    template<typename R>
    friend ostream& operator<<(ostream& out, const node<T> &d);

    template<typename R>
    friend istream& operator>>(istream& in, node<T> &d);

    T data;
    node<T>* ptr;


private:

    void copy(const node<T>& other)
    {
        data = other.data;
        ptr = NULL;
    }
};

// works
template<typename R>
ostream& operator<<(ostream& out, const node<R> &n)
{
    out<<n.data<<endl;
    return out;
}

// private error
template<typename R>
istream& operator>>(istream& in, node<R> &n)
{
    if (&std::cin == &in)
    {
        std::cout << "Data: ";



        in >> n.setData();
        n.ptr = NULL;
    }
    //    in >> n;

    return in;
}

#endif // NODE_H
