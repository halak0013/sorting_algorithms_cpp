#include <iostream>
#include "filePro.cpp"
#include "include/sort_algos.hpp"

using namespace std;

int main()
{
    vector<char> file = readFile("../data/random/32K_string_1");
    bool a = true;
    if (a)
    {
        /* cout << runAlgo(SType::SELLECTION, file) << " sellection" << endl;
        cout << runAlgo(SType::INSERTION, file) << " insertion" << endl;
        cout << runAlgo(SType::MERGE, file) << " merge" << endl;
        cout << runAlgo(SType::WAY_3_MERGE, file) << " merge3" << endl;
        cout << runAlgo(SType::QUICK_HOARE, file) << " hoare" << endl;
        cout << runAlgo(SType::QUICK_LOMUTO, file) << " lomuto" << endl;
        cout << runAlgo(SType::HEAP, file) << " heap" << endl;
        cout << runAlgo(SType::SHEELSORT, file) << " shell" << endl; */
    }

}

