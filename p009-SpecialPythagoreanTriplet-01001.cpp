/*
 *  Special Pythagorean triplet
    Problem 9

    A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
    a^2 + b^2 = c^2

    For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

    There exists exactly one Pythagorean triplet for which a + b + c = 1000.
    Find the product abc.
*/

#include "_eulertools.h"

using namespace std;


int main()
{
    // display numeric numbers
    cout.setf(ios::fixed);

    int lim = 1000;
    bool stop = false;

    for (int a = 1; a <= lim && not stop; ++a){
        for (int b = 1; b <= lim && not stop; ++b){
            for (int c = 1; c <= lim && not stop; ++c){
                if (pow(a, 2) + pow(b, 2) == pow(c, 2)){
                    if (a + b + c == 1000){
                        cout << a << ", " << b << ", " << c << " -> ";
                        cout << pow(a, 2) << ", " << pow(b, 2) << ", " << pow(c, 2) << endl;
                        cout << "BINGO:" << a << " - " << b << " - " << c << endl;
                        cout << "sum: " << a * b * c << endl;
                        stop = true;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
