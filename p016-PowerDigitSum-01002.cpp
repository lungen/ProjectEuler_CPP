/*
Power digit sum
Problem 16

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
*/

#include "_eulertools.h"

using namespace std;

// global array
int array[512] = {0};

void f(int n)
{
    int counter = 1;
    int pointer = 0;
    // while -> power function
    while (counter <= n)
    {
        int result = 0;
        int suma = 0;
        int carry = 0;

        for (int i = 0;i <= pointer; ++i)
        {
           result = array[i] * 2 + carry;
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
    f(1000);
    printArray(array, 512);

    // sum of array
    int sumOfArray = 0;
    for (int i = 0; i < 512; ++i) sumOfArray += array[i];
    cout << "sum: " << sumOfArray << endl;

    return 0;
}
