/*
 * Sum square difference
 * Problem 6
 *
 * The sum of the squares of the first ten natural numbers is,
 * 1^2 + 2^2 + ... + 10^2 = 385
 *
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)^2 = 55^2 = 3025
 *
 * Hence the difference between the sum of the squares of the first ten natural numbers and
 * the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred natural
 * numbers and the square of the sum.
 *
*/

#include "_eulertools.h"

using namespace std;


int main()
{
    // display numeric numbers
    cout.setf(ios::fixed);

    unsigned long long sum1 = 0;
    unsigned long long sum2 = 0;

    for (int i = 1; i <= 100; ++i){
        sum1 += pow(i, 2);
        sum2 += i;
    }

    sum2 = pow(sum2, 2);
    cout << "sum1: " << sum1 << endl;
    cout << "sum2: " << sum2 << endl;
    cout << "sum difference: " << sum2 - sum1 << endl;

    return 0;
}
