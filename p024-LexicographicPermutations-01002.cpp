/*
Lexicographic permutations
Problem 24

A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the
digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically,
we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?


https://www.quora.com/How-would-you-explain-an-algorithm-that-generates-permutations-using-lexicographic-ordering

For the impatient, we will start with the actual algorithm. Here it is.
Suppose that P[1..n] is a permutation of 1 through n.
We can construct the next permutation in lexicographic order by following these simple steps:

    (1) Find the largest x such that P[x]<P[x+1].
        (If there is no such x, P is the last permutation.)

    (2) Find the largest y such that P[x]<P[y].

    (3) Swap P[x] and P[y].

    (4) Reverse P[x+1 .. n].
*/


#include "_eulertools.h"

using namespace std;

// global
vector<int> v;


// returns the next lexicographic-order permutation
void nextPermutation()
{
    int x = -1;

    // (1) Find the largest x such that P[x]<P[x+1].
    for (int i = 0; i < v.size() - 1; ++i){
        if (v[i] < v[i + 1]) x = i;
    }

    // (1.1) if there is no such x, P is the last permutation.
    if (x == -1) return;

    // (2) Find the largest y such that P[x]<P[y].
    vector<int> v2;

    for (int i = x + 1; i < v.size(); ++i){
        if (v[i] > v[x]) v2.push_back(v[i]);
    }

    sort(v2.begin(), v2.end());
    // find the smallest v2-value in v
    auto it =  find(v.begin(), v.end(), v2[0]);
    // get the index of the smallest v2-value in v
    auto y = distance(v.begin(), it);
    //cout << "index (y): " << y << endl;

    // (3) Swap P[x] and P[y].
    int tmp = -1;
    tmp = v[x];
    v[x] = v[y];
    v[y] = tmp;

    // (4) Reverse P[x+1 .. n].
    int i = x + 1;
    int delim = v.size();
    while (i < delim){
        int tmp = v[i];
        v[i] = v[delim - 1];
        v[delim - 1] = tmp;
        ++i;
        --delim;
    }
}


int main()
{
    int lim = 1000000;
    v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    while (lim > 1){
        nextPermutation();
        --lim;
    }

    printVectorInt(v);
    return 0;
}
