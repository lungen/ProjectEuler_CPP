/*
Lattice paths
Problem 15

Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down,
there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
*/

/*
using gmp for big numbers operation

howto compile:
https://gmplib.org/manual/Headers-and-Libraries.html#Headers-and-Libraries
*/

#include "_eulertools.h"
#include <gmp.h>

using namespace std;

unsigned long long factorial(unsigned long long n)
{
    if (n == 1) return 1;
    return n * factorial(n - 1);
}

int main()
{
    // gmp init
    // https://gmplib.org/manual/Nomenclature-and-Types.html#Nomenclature-and-Types

    mpz_t sum;

    //mpz_t zaehler = factorial(4);
    //mpz_t nenner = factorial(2);
    mpz_t zaehler, nenner;
    mpz_inits(zaehler, factorial(4));
    mpz_inits(nenner, factorial(2));

    cout << "z: " << zaehler << " n: " << nenner << endl;
    cout << (zaehler / (nenner * nenner));
    return 0;
}
