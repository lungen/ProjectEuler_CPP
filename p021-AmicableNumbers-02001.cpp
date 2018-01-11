/*
Amicable numbers
Problem 21

Let d(n) be defined as the sum1 of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b
are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110;
therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum1 of all the amicable numbers under 10000.
*/


#include "_eulertools.h"

using namespace std;

// global
int lim;
int sumTotal;
vector<int> v;
vector<int> v2;


// n has to be > 1;
void f(int n = 2)
{
    while (n < lim){
        int suma = 0;
        int sumb = 0;

        // increment and continue if number is a prime
        if (isPrime(n)){
            ++n;
            continue;
        }

        // get proper divisors of n
        v = divisorGenerator(n);

        // get sum a
        for (int i = 0; i < v.size() - 1; ++i) suma += v[i];

        // continue if n == sum a == b
        if (n == suma) {
            ++n;
            continue;
        }

        // get proper divisors of b
        v2 = divisorGenerator(suma);

        // get sum b
        for (int i = 0; i < v2.size() - 1; ++i) sumb += v2[i];

        // add to total sum if OK
        if (sumb == n) sumTotal += n;

        ++n;
    }
}


int main()
{
    lim = 10000;
    f(2);
    cout << "sum: " << sumTotal;

    return 0;
}
