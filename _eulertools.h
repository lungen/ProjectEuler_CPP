#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

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

bool isPalindrome(int x)
{
    string s = to_string(x);
    string copy(s);
    reverse(s.begin(), s.end());
    if (s == copy) return true;
    return false;
}
