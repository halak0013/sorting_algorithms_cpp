#include <vector>

typedef unsigned long u_long;
using namespace std;
//https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/
class QuickHoare
{
private:

    int partionHoare(vector<char> &liste, int low, int high);
    int partionLomuto(vector<char> &liste, int low, int high);
    void quickSortHoare(vector<char> &liste, int low, int high);
    void quickSortLomuto(vector<char> &liste, int low, int high);

public:
    void quickSort(vector<char> liste, bool isHoare);
    u_long c = 0;
};
