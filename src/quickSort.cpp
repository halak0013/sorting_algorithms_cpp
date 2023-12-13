#include "include/quickSort.hpp"

int QuickHoare::partionHoare(vector<char> &liste, int low, int high)
{
    int pivot = liste[low];
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do
        {
        c++;
            i++;
        } while (liste[i] < pivot);
        do
        {
            j--;
        } while (liste[j] > pivot);
        if (i >= j)
            return j;
        swap(liste[i], liste[j]);
    }
}

int QuickHoare::partionLomuto(vector<char> &liste, int low, int high)
{
    int pivot = liste[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        c++;
        if (liste[j] <= pivot)
        {
            i++;
            swap(liste[i], liste[j]);
        }
    }
    swap(liste[i + 1], liste[high]);
    return (i + 1);
}

void QuickHoare::quickSortHoare(vector<char> &liste, int low, int high)
{
    if (low < high)
    {
        int pi = partionHoare(liste, low, high);
        quickSortHoare(liste, low, pi);
        quickSortHoare(liste, pi + 1, high);
    }
}

void QuickHoare::quickSortLomuto(vector<char> &liste, int low, int high)
{
    if (low < high)
    {
        int pi = partionLomuto(liste, low, high);
        quickSortLomuto(liste, low, pi-1);
        quickSortLomuto(liste, pi + 1, high);
    }
}

void QuickHoare::quickSort(vector<char> liste, bool isHoare)
{
    c=0;
    if (isHoare)
        quickSortHoare(liste, 0, liste.size() - 1);
    else
        quickSortLomuto(liste, 0, liste.size() - 1);
}
