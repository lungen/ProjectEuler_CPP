/*
Reciprocal cycles
Problem 26

A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with
denominators 2 to 10 are given:

    1/2	= 	0.5
    1/3	= 	0.(3)
    1/4	= 	0.25
    1/5	= 	0.2
    1/6	= 	0.1(6)
    1/7	= 	0.(142857)
    1/8	= 	0.125
    1/9	= 	0.(1)
    1/10	= 	0.1

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle.
It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/

/*  LINKS

    https://www.geeksforgeeks.org/divide-large-number-represented-string/
*/

#include "_eulertools.h"
#include <iostream>

using namespace std;


// A function to perform division of large numbers
string longDivision(int number, int divisor)
{
    // As result can be very large -> store it in string
    string ans;

    int len = 2000;

    // add zeros if number < divisor
    int temp = 0;
    while (number < divisor){
        temp = number / divisor;
        number = (number % divisor) * 10;
        ans += temp + '0';
    }

    // Repeatedly
    while (ans.length() <= len)
    {
        // Store result in answer i.e. temp / divisor
        temp = number / divisor;
        ans += temp + '0';
        number = (number % divisor) * 10;

        if (number % divisor == 0){
            break;
        }
    }

    // insert coma into result
    ans.insert(1, 1, ',');

    return ans;
}

int findPattern(string nr)
{

    int res = 0;
    size_t found;
    // lets say that the minimum pattern-length is 6 (1/7)
    string sub = nr.substr(0, 6);

    found = nr.find(sub, 2);
    sub = nr.substr(0, found);
    found = nr.find(sub, 2);

    res = found;
    return res;
}

// Driver programm to test longDivision()
int main()
{
    string res;
    int number = 1;
    int maxLength = 0;
    int maxDivisor = 0;

    int divisor = 2;
    while (divisor <= 1000){
        if (isPrime(divisor)){
            res = longDivision(number, divisor);
            // start (slice) from comma
            if (findPattern(res.substr(2)) > maxLength){
                maxLength = findPattern(res.substr(2));
                maxDivisor = divisor;
            }
        }
        ++divisor;
    }
    cout << "divisor: " << maxDivisor << " Length: " << maxLength << endl;
    return 0;
}

