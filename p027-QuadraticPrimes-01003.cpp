/*
Quadratic primes
Problem 27

Euler discovered the remarkable quadratic formula:

n^2+n+41

It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤39.
However, when n=40,40^2+40+41=40(40+1)+41 is divisible by 41,
and certainly when n=41,412+41+41 is clearly divisible by 41.

The incredible formula n^2−79n+1601
was discovered, which produces 80 primes for the consecutive values 0≤n≤79.
The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

    n^2+an+b

, where |a|<1000 and |b|≤1000

where |n|
is the modulus/absolute value of n
e.g. |11|=11 and |−4|=4

Find the product of the coefficients, a and b, for the quadratic expression that produces
the maximum number of primes for consecutive values of n, starting with n=0.

*/

#include "_eulertools.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int res;
    int lim = 1000;
    int maxRes = 0;
    int counter = 0;
    int product = 0;
    vector<int> v;


    for (int b = -1000; b <= lim; ++b)
    {
        for (int a = -999; a < lim && a <= b; ++a)
        {
            for (int n = 0; n <= lim && n <= b; ++n)
            {
                res = (n *n) + (a * n) + b;
                if (isPrime(res))
                {
                    counter += 1;
                } else {
                    if (counter > maxRes){
                        maxRes = counter;
                        product = a * b;

                        if(v.size() > 0){
                            while(v.size() > 0) v.erase(v.begin());
                        }
                        v.push_back(a);
                        v.push_back(b);
                    }
                    counter = 0;
                    break;
                }
            }
        }
    }

    cout << endl;
    printVectorInt(v);
    cout << "\nmaxRes: " << maxRes;
    cout << "\nproduct: " << product;

    return 0;
}


