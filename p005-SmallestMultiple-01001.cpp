/*
Smallest multiple
Problem 5

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include "_eulertools.h"

using namespace std;


int main()
{
    // display numeric numbers
    cout.setf(ios::fixed);

    int n = 0;
    int x = 20;
    bool stop = false;

    while (not stop){
        for (int i = 1; i <= 20; i += 1){
            if (n == 0) break;
            if ((n % i) != 0){
                break;
            } else {
                if (i == 20){
                    cout << "B I N G O: " << n << " - " << i << endl;
                    stop = true;
                }
            }
        }
        n += 20;
    }

    return 0;
}
