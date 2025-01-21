#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long u_long;

//https://www.geeksforgeeks.org/heap-sort/
class HeapSort
{
private:
    void heapify(vector<char> &liste , int N, int i);

public:
    HeapSort();
    void heapSort(vector<char> liste);
    u_long c = 0;
};

