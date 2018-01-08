/*
Factorial digit sum
Problem 20

n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/


#include "_eulertools.h"

using namespace std;

// global array
int array[256] = {0};

void f(int n)
{
    int counter = 1;
    int pointer = 0;
    // while -> factoral-function
    while (counter <= n)
    {
        int result = 0;
        int suma = 0;
        int carry = 0;

        for (int i = 0;i <= pointer; ++i)
        {
           result = array[i] * counter + carry;
           suma = result % 10;
           carry = result / 10;
           array[i] = suma;
           if (carry > 0 && i == pointer) ++pointer;
        }
        ++counter;
    }
    cout << endl;
    cout << "pointer: " << pointer << endl;
}


int main()
{
    array[0] = 1;
    f(100);
    printArray(array, 256);

    // sum of array
    int sumOfArray = 0;
    for (int i = 0; i < 256; ++i) sumOfArray += array[i];
    cout << "sum: " << sumOfArray << endl;

    return 0;
}
