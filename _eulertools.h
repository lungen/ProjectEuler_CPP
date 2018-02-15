#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

// *** *** *** *** *** *** *** SYSTEM ** *** *** *** *** *** *** *** *** *** *** *** ***
void showLimits() {
  std::cout
    << "static_cast int char: " << static_cast< int >(std::numeric_limits< char >::max()) << "\n"
    << "static_cast int int: " << static_cast< int >(std::numeric_limits< unsigned char >::max()) << "\n"
    << "short: " << std::numeric_limits< short >::max() << "\n"
    << "unsigned short: " << std::numeric_limits< unsigned short >::max() << "\n"
    << "int: " << std::numeric_limits< int >::max() << "\n"
    << "unsigned int: " << std::numeric_limits< unsigned int >::max() << "\n"
    << "long: " << std::numeric_limits< long >::max() << "\n"
    << "unsigned long: " << std::numeric_limits< unsigned long >::max() << "\n"
    << "long long: " << std::numeric_limits< long long >::max() << "\n"
    << "unsigned long long: " << std::numeric_limits< unsigned long long >::max() << "\n";
}

// *** *** *** *** *** *** *** ARRAY ** *** *** *** *** *** *** *** *** *** *** *** ***
void printArray (int arg[], int length)
{
    cout <<"-> " << __func__ << ": " << endl;
    for (int n=0; n<length; ++n)
    cout << arg[n] << ' ';
    cout << '\n';
}

// https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function#8767247
template <size_t rows, size_t cols>
void process_2d_array_template(int (&array)[rows][cols])
{
    std::cout << __func__ << std::endl;
    for (size_t i = 0; i < rows; ++i)
    {
        std::cout << i << ": ";
        for (size_t j = 0; j < cols; ++j)
            /*std::cout << array[i][j] << '\t';*/
            std::cout << array[i][j] << ' ';
        std::cout << std::endl;
    }
}

// *** *** *** *** *** *** ***  VECTORS *** *** *** *** *** *** *** *** *** ***
void printVectorStr(vector<string>& v)
{
    for (int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
}

void printVectorInt(vector<int>& v)
{
    cout << "-> printVectorInt: v.size(): " << v.size() << endl;
    for (int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
}
// *** *** *** *** *** *** *** PRIME NUMBERS *** *** *** *** *** *** *** *** *** ***
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

// *** *** *** *** *** *** *** MISC *** *** *** *** *** *** *** *** *** *** *** **
bool isPalindrome(int x)
{
    string s = to_string(x);
    string copy(s);
    reverse(s.begin(), s.end());
    if (s == copy) return true;
    return false;
}

// TRIANGULAR NUMBER -> get nth triangle number, f.e: T3 = 6.
int getTriangleNumber(int n)
{
    unsigned long long suma = 0;
    suma = (n * (n + 1))/ 2;
    return suma;
}

// DIVISOR GENERATOR -> get all divisors of a number
std::vector<int> divisorGenerator(int n)
{
    std::vector<int> v;
    std::vector<int> largeDivisors;

    for (int i = 1;i <= sqrt(n); ++i)
    {
       if ((n % i) == 0)
       {
           // add small divisor
           v.push_back(i);

           if ((i * i != n))
           {
               // add large divisor
               largeDivisors.push_back(n / i);
           }
       }
    }

    // reverse
    std::reverse(largeDivisors.begin(), largeDivisors.end());

    // merge the vectors
    v.insert(std::end(v), std::begin(largeDivisors), std::end(largeDivisors));

    return v;
}
