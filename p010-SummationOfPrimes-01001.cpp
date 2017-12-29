/*
 *  Summation of primes
    Problem 10

    The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

    Find the sum of all the primes below two million.

*/

#include "_eulertools.h"

using namespace std;


int main()
{
    // display numeric numbers
    cout.setf(ios::fixed);

    unsigned long long sum = 0;
    unsigned long int i = 1;
    unsigned long int lim = 2000000;

    for (i; i < lim; i+=2){
        if (isPrime(i)) sum += i;
    }

    // add (missing) prime number 2 to the sum.
    sum += 2;
    cout << "sum: " << sum << endl;

    return 0;
}
