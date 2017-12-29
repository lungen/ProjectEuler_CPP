/*
 * Largest prime factor
 * Problem 3
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600 851 475 143 ?
 *
 * ranges:
 * https://stackoverflow.com/questions/1819189/what-range-of-values-can-integer-types-store-in-c
*/

#include <iostream>
#include <cmath>
#include "_eulertools.h"

using namespace std;

int main()
{
    unsigned long long int p = 600851475143;
    //int p = 13195;
    long long int s = 0;
    bool stop = false;
    int i = 2;

    // display numeric numbers
    cout.setf(ios::fixed);

    while (not stop)
    {
        // modulo -> check how the prime number (i) is dividing the super number
        // if s == 0 -> factor found
        // else interate prime number
        s = p % i;

        // interate prime number
        if (s != 0){
            ++i;
            while (not isPrime(i)) ++i;
        }

        // factor found
        if (s == 0){
            p = p / i;
            cout << "p: " << p << " i: " << i << " s: " << s << endl;
        }

        // largest prime number found
        if (p == i){
            stop = true;
        }
    }

    cout << "max prime factor: " << i << endl;
    return 0;
}
