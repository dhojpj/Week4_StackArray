#include <iostream>
#include "stack.h"
//#include "stackArray.h"
using namespace std;

// test out the stach.h


int main()
{
    //    stackArray<char> *s = new stackArray<char>;

    //    for (size_t i = 0; i < 5; ++i)
    //    {


    ////        cout << "size = " << s->size() << endl;
    //            s->push('a' + i);
    //    }

    //           cin >> *s;
    //           cin.ignore();


    //    for (size_t i = 0; i < 10; ++i)
    //    {
    ////        cout << "size = " << s->size() << endl;
    //        cout << i << " = " << s->pop() << endl;
    //    }


    //    cout << *s << endl;

    //    int **ptr = new int*[10]; // array of pointers

    //    for(int i = 0; i < 10; i++)
    //    {
    //       *(ptr+i) = new int [10];

    //    }

    //     cout << *(*(ptr+2) + 2) << endl;

    //     cout << ptr[2][2] << endl;
    //     cout << *(ptr[2] + 2) << endl;



//    stack<int> *s = new stack<int>;
    stack<char> *s = new stack<char>;

//    for (size_t i = 0; i < 5; ++i)
//    {

//        cout << "i = " << (char)('a' + i) << endl;
//        s->push('a'+i);
//    }


    cin >> *s;

    cout << "size = " << s->size() << endl;


    cout << *s << endl;




    return 0;
}

