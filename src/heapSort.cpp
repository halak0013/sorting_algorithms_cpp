#include "include/heapSort.hpp"

HeapSort::HeapSort()
{
}

void HeapSort::heapify(vector<char> &liste, int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    c++;
    if (l < N && liste[l] > liste[largest])
        largest = l;

    if (r < N && liste[r] > liste[largest])
        largest = r;

    if (largest != i)
    {
        swap(liste[i], liste[largest]);
        heapify(liste, N, largest);
    }
}

void HeapSort::heapSort(vector<char> liste){
    int s = liste.size();
    for (int i = s / 2 - 1; i >= 0; i--)
        heapify(liste, s, i);

    for (int i = s - 1; i > 0; i--)
    {
        swap(liste[0], liste[i]);
        heapify(liste, i, 0);
    }
}
