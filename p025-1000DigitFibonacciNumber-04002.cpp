/*
1000-digit Fibonacci number
Problem 25

The Fibonacci sequence is defined by the recurrence relation:

    Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.

Hence the first 12 terms will be:

    F1 = 1
    F2 = 1
    F3 = 2
    F4 = 3
    F5 = 5
    F6 = 8
    F7 = 13
    F8 = 21
    F9 = 34
    F10 = 55
    F11 = 89
    F12 = 144


The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/


#include "_eulertools.h"
#include <queue>

using namespace std;


/// How to set initial size of std::vector?
// https://stackoverflow.com/questions/11457571/how-to-set-initial-size-of-stdvector#11457629

/// Array of pointers to arrays
// https://stackoverflow.com/questions/11363226/array-of-pointers-to-arrays

int main()
{
    /// INIT
    const int SIZE = 1000;
    bool stop = false;

    // arrays
    int a1 [SIZE] = {1};  // F1 = 1;
    int a2 [SIZE] = {1};  // F2 = 2;
    int a3 [SIZE] = {0};

    // pointes to arrays
    int *pa1;
    int *pa2;
    int *pa3;

    // array - Queue
    queue<int*> myQueue;

    int lim = 0;
    int findIndex = 999;


    /// START
    cout << "-> START" << endl;

    myQueue.push(a3);
    myQueue.push(a1);
    myQueue.push(a2);

    int c = 3;
    while (not stop){
        // LOOP - SWAPING
        pa3 = myQueue.back();
        pa1 = myQueue.front();
        myQueue.pop();
        pa2 = myQueue.front();
        myQueue.push(pa1);
        // END SWAPING

        int result = 0;
        int suma = 0;
        int carry = 0;

        //cout << "\nc: " << c << endl;
        ////////////////////////////////////////////////////////////////////////////////
        //
        // Fn = Fn-1 + Fn-2: addition over arrays f.e:
        //
        // Index:   0 1 2 3
        // ---------------------
        // Fn-2:    8 0 0 0
        // Fn-1:    3 1 0 0
        // ---------------------
        // Fn  :    1 2 0 0
        //            | ->  lim = 1
        //
        // Fn = 8 + 13 = 21
        ////////////////////////////////////////////////////////////////////////////////
        int index = 0;
        while (index <= lim && not stop)
        {
            result = *(pa2 + index) + *(pa3 + index) + carry;
            suma = result % 10;
            carry = result / 10;

            if (carry > 0 && index == lim) ++lim;

            *(pa1 + index) = suma;

            if (lim == findIndex){
                *(pa1 + lim) = carry;

                cout << "\nLIM ------> STOP!" << endl;
                cout << "c: " << c << endl;
                cout << "lim: " << lim << endl;
                printArray(pa1, lim+1);
                stop = true;
            }
            ++index;
        }
        ++c;
    }
    cout << "-> END" << endl;
    return 0;
}
