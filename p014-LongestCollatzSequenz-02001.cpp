/*
Longest Collatz sequence
Problem 14

The following iterative sequence is defined for the set of positive longegers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/


#include "_eulertools.h"
#include <map>

using namespace std;

// global map (dictionary)
map<long, long>d;

// define recursion
long f(long n)
{
    /// if key is not in dictionary
    if (d.count(n) == 0)
    {
        long result = 0;

        if ((n % 2) == 0)           //even number
        {
            result = n / 2;
        } else {
            result = (3 * n) + 1;   //odd number
        }

        d[n] = 1 + f(result);       //add new key
        return d[n];                //call recursion

    } else {

        return d[n];
    }
}

int main()
{
    d[1] = 1;
    int longestTail = 0;
    int longestNumber = 0;
    int x = 1;
    while(x <= 1000000)
    {
        if (f(x) > longestTail)
        {
            longestTail = f(x);
            longestNumber = x;
        }
        ++x;
    }

    cout << "longestNumber: " << longestNumber << ", longestTail: " << longestTail << endl;
    return 0;
}
