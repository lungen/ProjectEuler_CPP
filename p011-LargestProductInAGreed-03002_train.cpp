/*
Largest product in a grid
Problem 11

In the 20×20 grid below, four numbers along a diagonal line have been marked in red.

08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48

The product of these numbers is 26 × 63 × 78 × 14 = 1788696.

What is the greatest product of four adjacent numbers in the same direction
(up, down, left, right, or diagonally) in the 20×20 grid?

*/

// arrays
// http://www.academia.edu/6133228/Arrays_and_Strings_in_C_Programming

#include "_eulertools.h"
// http://www.dreamincode.net/forums/topic/95826-stringstream-tutorial/
#include <sstream>
#include <vector>

//using namespace std;


int main()
{
    // display numeric numbers
    cout.setf(ios::fixed);

    const char *sp1 =
        "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08"
        "49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00"
        "81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65"
        "52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91"
        "22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80"
        "24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50"
        "32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70"
        "67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21"
        "24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72"
        "21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95"
        "78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92"
        "16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57"
        "86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58"
        "19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40"
        "04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66"
        "88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69"
        "04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36"
        "20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16"
        "20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54"
        "01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48";

    const char *sp2 =
        "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 "
        "49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 "
        "81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 "
        "52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 "
        "22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 "
        "24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 "
        "32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 "
        "67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 "
        "24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 "
        "21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 "
        "78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 "
        "16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 "
        "86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 "
        "19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 "
        "04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 "
        "88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 "
        "04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 "
        "20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 "
        "20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 "
        "01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48";

    const char *sp3 =
        "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08\n"
        "49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00\n"
        "81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65\n"
        "52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91\n"
        "22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80\n"
        "24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50\n"
        "32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70\n"
        "67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21\n"
        "24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72\n"
        "21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95\n"
        "78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92\n"
        "16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57\n"
        "86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58\n"
        "19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40\n"
        "04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66\n"
        "88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69\n"
        "04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36\n"
        "20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16\n"
        "20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54\n"
        "01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48";

    // usisng sp3 because of next line \n
    std::stringstream iss(sp3);
    std::string line;
    int number;
    const int ROWS = 20;
    const int COLS = 20;
    int array[ROWS][COLS];

    // init array from stringstream
    int row = 0;
    int col = 0;
    while (std::getline(iss, line)){
        //cout << line << std::endl;
        std::stringstream issline(line);
        while (issline >> number){
            //cout << number << std::endl;
            array[row][col] = number;
            ++col;
        }
        col = 0;
        ++row;
    }

    // print array
        for (row = 0; row < 20; ++row){
            for (col = 0; col < 20; ++col){
                cout << array[row][col] << " ";
            }
            cout << std::endl;
        }

    // get size of array
    int sizeArrayRow = sizeof array / sizeof array[0];
    int sizeArrayCol = sizeof array[0] / sizeof(int);
    cout << "row-size of array: " << sizeArrayRow << std::endl;
    cout << "col-size of array: " << sizeArrayCol << std::endl;

    unsigned long long totalSum = 0;

    // get biggest sum in horizont lines (left/right)
    unsigned long long hSum = 1;
    unsigned long long maxHsumLine = 0;
    unsigned long long maxHsum = 0;

    for (int row = 0; row < sizeArrayRow; ++row){
        for (int col = 0; col <= sizeArrayCol - 4; ++ col){
            for (int k = 0; k < 4; ++k){
                hSum *= array[row][col + k];
            }
            totalSum = max(totalSum, hSum);
            maxHsum = max(maxHsum, hSum);
            maxHsumLine = max(maxHsumLine, hSum);
            hSum = 1;
        }
        //cout << "max h-sum in line: " << "line: " << row << " sum: " << maxHsumLine << endl;
        maxHsumLine = 1;
    }
    cout << "max hSum: " << maxHsum << std::endl;

    // get biggest sum in vertical lines (up/down)
   unsigned long long vSum = 1;
   unsigned long long maxVsumLine = 0;
   unsigned long long maxVsum = 0;

   for (col = 0; col < sizeArrayCol; ++col){
        for (row = 0; row <= sizeArrayRow - 4; ++row){
           for (int k = 0; k < 4; ++k){
               vSum *= array[row + k][col];
           }
           totalSum = max(totalSum, vSum);
            maxVsum = max(maxVsum, vSum);
            maxVsumLine = max(maxVsumLine, vSum);
            vSum = 1;
       }
        //cout << "max v-Sum in col: " << "col: " << col << " sum: " << maxVsumLine << endl;;
        maxVsumLine = 1;
   }
   cout << "max vSum: " << maxVsum << std::endl;

   // get biggest sum in diagonal lines - start from left side
   unsigned long long dSum = 1;
   unsigned long long maxDsumLine = 0;
   unsigned long long maxDsum = 0;

   for (row = 0; row <= sizeArrayRow - 4; ++row)
   {
       for (col = 0; col <= sizeArrayCol - 4; ++col)
       {
           for (int k = 0; k < 4; ++k)
           {
               dSum *= array[row + k][col +k];
           }
           totalSum = max(totalSum, dSum);
           maxDsumLine = max(maxDsumLine, dSum);
           maxDsum = max(maxDsum, dSum);
           dSum = 1;
       }
       //cout << "max dsum row: " << "row: " << row << "sum: " << maxDsumLine << endl;
       maxDsumLine = 0;
   }
   cout << "max dSum: " << maxDsum << std::endl;


   // get biggest sum in diagonal lines - start from right side
   unsigned long long d2Sum = 1;
   unsigned long long maxD2sumLine = 0;
   unsigned long long maxD2sum = 0;


   for (col = sizeArrayCol - 1; col >= 3; --col)
   {
       for (row = 0; row <= sizeArrayRow - 4; ++row)
       {
           for (int k = 0; k < 4; ++k)
           {
               d2Sum *= array[row + k][col - k];
           }
           totalSum = max(totalSum, d2Sum);
           maxD2sumLine = max(maxD2sumLine, d2Sum);
           maxD2sum = max(maxD2sum, d2Sum);
           d2Sum = 1;
       }
       //cout << "max d2sum row: " << "row: " << row << "sum: " << maxD2sumLine << endl;
       maxD2sumLine = 0;
   }
   cout << "max d2Sum: " << maxD2sum << std::endl;

   cout << "max Sum total: " << totalSum << std::endl;

    return 0;
}
