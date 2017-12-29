/*
 * Largest palindrome product
 * Problem 4
 *
 * A palindromic number reads the same both ways. The largest palindrome made from the
 * product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 *
// reverse string:
// https://stackoverflow.com/questions/4951796/how-to-reverse-an-stdstring

// convert int to string:
// https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c#5591169
*/


// not necessary to include header-files -> are already included in _eulertools.h
/*
#include <iostream>
#include <string>
#include <algorithm>
*/


#include "_eulertools.h"

using namespace std;


int main()
{
    // display numeric numbers
    cout.setf(ios::fixed);

    unsigned long maxPalindrome = 0;
    unsigned long result = 0;

    for (int a = 100; a < 1000; ++a){
        for (int s = 100; s < 1000; ++s){
            result = a * s;
            if (isPalindrome(result)) maxPalindrome = max(maxPalindrome, result);
        }
    }

    cout << "maxPalindrome: " << maxPalindrome << endl;
    return 0;
}
