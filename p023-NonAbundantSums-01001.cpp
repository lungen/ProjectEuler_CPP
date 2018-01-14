/*
Non-abundant sums
Problem 23

A perfect number is a number for which the sum of its proper divisors is exactly equal to
the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28,
which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called
abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be
written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown
that all integers greater than 28123 can be written as the sum of two abundant numbers.
However, this upper limit cannot be reduced any further by analysis even though it is known that
the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/


#include "_eulertools.h"
#include <map>

using namespace std;

// global
int lim;
vector<int> v;      // vector of abundant numbers
map<int, int> m;    // map of all numbers until lim


int main()
{
    lim = 28123;
    vector<int> vsum;
    long suma = 0;

    for (int i = 1; i <= lim; ++i){  // get abundant numbers
        vsum = divisorGenerator(i);
        vsum.pop_back();

        while(vsum.empty() == false){
        //while(!vsum.empty()){
            suma += vsum.back();
            vsum.pop_back();
        }

        if (suma > i) v.push_back(i);
        suma = 0;
    }

    cout << "size: " << v.size() << "\n";

    for (int i = 1; i <= lim; ++i){
        m.insert(pair<int, int>(i, i));
    }

    // iterate and remove the sums which consists of two abundant numbers
    long n = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = i; j < v.size(); ++j)
        {
            n = v[i] + v[j];                    // sum of two abundant numbers
            if (m.count(n) == 1) m.erase(n);    // if found -> remove from map
        }
    }

    // iterate over map and get the total sum
    long totalSum = 0;
    for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it){
        totalSum += it->first;
    }

    cout << "total sum: " << totalSum << endl;

    return 0;
}
