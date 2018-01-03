#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

// *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***
// *** *** *** *** *** *** *** PRIME NUMBERS * *** *** *** *** *** *** *** *** ***
// *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

bool isPrime(int x)
{
    int n = 0;
    n = abs(x);

    if (n < 2) return false;
    if (n == 2) return true;  // 2 -> first prime number
    if ((n & 1) == 0) return false;  // check if even number

    for(auto i = 3; i < int(pow(n, 0.5)) + 1; i+=2)  // iterate
    {
        if ((n % i ) == 0) return false;  // check if n is divisible by other numbers
    }

    return true;
}


// *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***
// *** *** *** *** *** *** *** MISC *** *** *** *** *** *** *** *** *** *** *** **
// *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

bool isPalindrome(int x)
{
    string s = to_string(x);
    string copy(s);
    reverse(s.begin(), s.end());
    if (s == copy) return true;
    return false;
}

// https://en.wikipedia.org/wiki/Triangular_number
// get nth triangle number, f.e: T3 = 6.
int getTriangleNumber(int n)
{
    unsigned long long suma = 0;
    suma = (n * (n + 1))/ 2;
    return suma;
}

// DIVISOR GENERATOR; get all divisors of a number
std::vector<int> divisorGenerator(int n)
{
    std::vector<int> v;
    std::vector<int> largeDivisors;

    for (int i = 1;i <= sqrt(n); ++i)
    {
       if ((n % i) == 0)
       {
           // add small divisor
           v.push_back(i);

           if ((i * i != n))
           {
               // add large divisor
               largeDivisors.push_back(n / i);
           }
       }
    }

    // reverse
    std::reverse(largeDivisors.begin(), largeDivisors.end());

    // merge the vectors
    v.insert(std::end(v), std::begin(largeDivisors), std::end(largeDivisors));

    return v;
}
