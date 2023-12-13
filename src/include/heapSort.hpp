#include <iostream>
#include <vector>
using namespace std;
//https://www.geeksforgeeks.org/heap-sort/
class HeapSort
{
private:
    void heapify(vector<char> &liste , int N, int i);

public:
    HeapSort();
    void heapSort(vector<char> liste);
    int c = 0;
};

