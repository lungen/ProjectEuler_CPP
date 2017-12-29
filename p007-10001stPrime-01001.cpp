/*
 10001st prime
 Problem 7

 By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, 
 we can see that the 6th prime is 13.

 What is the 10 001st prime number?
*/

#include "_eulertools.h"

using namespace std;


int main()
{
    // display numeric numbers
    cout.setf(ios::fixed);

    int i = 2;
    int counter = 0;

    while (counter <= 10001){
        if (isPrime(i)){
            ++counter;

            if (counter == 10001){
                cout << "BINGO: " << i << endl;
                break;
            }
        }
        ++i;
    }

    return 0;
}
