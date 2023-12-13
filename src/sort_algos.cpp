
#include "include/sort_algos.hpp"
using namespace std;

vector<double> runAlgo(SType type, vector<char> i_a)
{
    int c = 0;
    auto start = chrono::high_resolution_clock::now();
    switch (type)
    {
    case SELLECTION:
        c = sellectionSort(i_a);
        break;
    case INSERTION:
        c = insertionSort(i_a);
        break;
    case SHEELSORT:
        c = shellSort(i_a);
        break;
    case MERGE:
        c = mergeSort(i_a);
        break;
    case WAY_3_MERGE:
        c = mergeSort3(i_a);
        break;
    case QUICK_LOMUTO:
        c = quickSortLH(i_a, false);
        break;
    case QUICK_HOARE:
        c = quickSortLH(i_a, true);
        break;
    case HEAP:
        c = heapSort(i_a);
        break;
    default:
        break;
    }
    auto end = chrono::high_resolution_clock::now();

    // measure time between two lines of code
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    double seconds = static_cast<double>(duration.count()) / 1000000.0;
    return {seconds, static_cast<double>(c)};
}

int heapSort(vector<char> i_a)
{
    HeapSort sortObj = HeapSort();
    sortObj.heapSort(i_a);
    return sortObj.c;
}

int quickSortLH(vector<char> i_a, bool isHoare)
{
    QuickHoare sortObj = QuickHoare();
    if (isHoare)
        sortObj.quickSort(i_a, isHoare);
    else
        sortObj.quickSort(i_a, isHoare);
    return sortObj.c;
}

int mergeSort(vector<char> i_a)
{
    MergeSort sortObj(i_a);
    sortObj.sort();
    return sortObj.c;
}

int mergeSort3(vector<char> i_a)
{
    MergeSort3 sortObj(i_a);
    sortObj.sort(i_a);
    return sortObj.c;
}

// https://bilgisayarkavramlari.com/2008/12/20/kabuk-siralama-shell-sort/
int shellSort(vector<char> i_a)
{
    int c = 0;
    unsigned int count = i_a.size();
    int gap = count / 2;
    while (gap > 0)
    {
        for (int i = gap; i < count; i++)
        {
            for (int k = i; k >= gap && i_a[k - gap] > (i_a[k]); k -= gap)
            {
                c++;
                swap(i_a[k], i_a[k - gap]);
            }
        }
        gap /= 2;
    }
    return c;
}

int insertionSort(vector<char> i_a)
{
    int c = 0;
    unsigned int count = i_a.size();

    for (int i = 0; i < count; i++)
    {
        for (int j = i; j > 0; j--)
        {
            c++;
            if (i_a[j] > i_a[j - 1])
                break;
            else
                swap(i_a[j], i_a[j - 1]);
        }
    }
    return c;
}

int sellectionSort(vector<char> i_a)
{
    int c = 0;
    unsigned int count = i_a.size();
    int min_i = 0;
    for (int i = 0; i < count - 1; i++)
    {
        min_i = i; //?store min index
        for (int j = i + 1; j < count-1; j++)
        {

            c++;
            if (i_a[j] < i_a[min_i])
                min_i = j;
        }
        swap(i_a[min_i], i_a[i]);
    }
    return c;
}

/* void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
} */

void print(vector<char> i_a)
{
    for (int i = 0; i < i_a.size(); i++)
        cout << i_a[i] << " ";
    cout << endl;
}