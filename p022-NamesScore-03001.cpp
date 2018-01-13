/*
Names scores
Problem 22

Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing
over five-thousand first names, begin by sorting it into alphabetical order. Then working out
the alphabetical value for each name, multiply this value by its alphabetical position in the
list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth
3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a
score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

/*
https://stackoverflow.com/questions/20715536/read-a-file-of-strings-with-quotes-and-commas-into-string-array
*/


#include "_eulertools.h"
#include <fstream>
#include <map>
// next libaries are being imported in _eulertools.h
//#include <iostream>
//#include <string>
//#include <vector>

using namespace std;

// global
unsigned long totalSum;
map<char, int> m;
vector<string> sortedItems;


// make name-score
void score(string s, int position)
{
    unsigned long suma = 0;
    char c;

    // iterate over name -> make sum
    for (int i = 0;i < s.size(); ++i){
        c = s[i];
        suma += m[c];  // get sum of char stored in dictionary (map)
    }
    totalSum += suma * position;
}


int main()
{
    // init map char with values
    // http://www.java2s.com/Code/Cpp/Data-Structure/Asimplemapcharandint.htm
    for (int i = 0; i < 26; ++i){
        m.insert(pair<char, int>('A' + i, 1 + i));
    }

    // print map values
    //for (map<char, int>::iterator it = m.begin(); it != m.end(); ++it){
        //cout << it->first << " " << it->second << "\n";;
    //}

    string file;
    string delimiter = ",";
    string token;
    size_t pos = 0;

    // !!! open file -> added "," to the end of the file
    // -> otherwise the last name will be not included !!!
    ifstream namesFile ("p022_names.txt");  // open the input file
    namesFile >> file;

    // split string into tokens
    while((pos = file.find(delimiter)) != string::npos){  // npos ->  means not found.
        token = file.substr(0, pos);
        token.replace(token.find('"'), 1, "");
        token.replace(token.find('"'), 1, "");
        // add to vector
        sortedItems.push_back(token);
        file.erase(0, pos + delimiter.length());
    }

    // sort names
    sort(sortedItems.begin(), sortedItems.end());

    // get total names-score
    for (int i = 0; i < sortedItems.size(); ++i){
        score(sortedItems[i], i + 1);
    }

    cout << "total names-score: " << totalSum << endl;

    return 0;
}
