#ifndef MERGESORT_HPP
#define MERGESORT_HPP
#include <vector>

typedef unsigned long u_long;
using namespace std;

class MergeSort
{
private:
    vector<char> list;

    vector<char> sort(vector<char>);
    void merge(vector<char>& left, vector<char>& right, vector<char>& result);

public:
    MergeSort(vector<char> listToSort);

    vector<char> getList();
    void sort();
    u_long c=0;

};
#endif // MERGESORT_HPP