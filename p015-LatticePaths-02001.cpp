/*
Lattice paths
Problem 15

Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down,
there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
*/

/*
    http://www.robertdickau.com/lattices.html
    http://www.robertdickau.com/manhattan.html
*/

#include "_eulertools.h"

using namespace std;


int main()
{
    const int SIZE = 21;
    unsigned long array[SIZE][SIZE] = {{}};

    // set complete first row (0) to the value 1
    for (int i = 0; i < SIZE; ++i){
        array[0][i] = 1;
    }
    // set complete first column (0) to the value 1
    for (int i = 0; i < SIZE; ++i){
        array[i][0] = 1;
    }

    for (int r = 1; r < SIZE; ++r){
        for (int c = 1; c < SIZE; ++c){
            array[r][c] = array[r][c -1] + array[r - 1][c];
        }
    }

    cout << "result: " << array[SIZE - 1][SIZE -1];
    return 0;
}
