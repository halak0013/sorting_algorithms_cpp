#include "include/mergeSort3.hpp"
#include <climits>
#include <algorithm>
MergeSort3::MergeSort3(vector<char> listToSort)
{
    list = listToSort;
}

void MergeSort3::merge(vector<char> &liste, int s, int mid1, int mid2, int end)
{
    vector<char> left_array(liste.begin() + s, liste.begin() + mid1 + 1);
    vector<char> mid_array(liste.begin() + mid1 + 1, liste.begin() + mid2 + 1);
    vector<char> right_array(liste.begin() + mid2 + 1, liste.begin() + end + 1);

    left_array.push_back(CHAR_MAX);
    mid_array.push_back(CHAR_MAX);
    right_array.push_back(CHAR_MAX);

    int ind_left = 0;
    int ind_mid = 0;
    int ind_right = 0;

    for (int i = s; i <= end; i++)
    {
        c++;
        char minimum = min(min(left_array[ind_left], mid_array[ind_mid]), right_array[ind_right]);
        if (minimum == left_array[ind_left])
        {
            liste[i] = left_array[ind_left];
            ind_left++;
        }
        else if (minimum == mid_array[ind_mid])
        {
            liste[i] = mid_array[ind_mid];
            ind_mid++;
        }
        else
        {
            liste[i] = right_array[ind_right];
            ind_right++;
        }
    }
}

vector<char> MergeSort3::sort(vector<char> liste)
{
    return sort(liste, 1, liste.size());
}

vector<char> MergeSort3::sort(vector<char> &liste, int start, int end)
{
    if (end - start < 1)
    {
        return liste;
    }
    else
    {
        int mid1 = start + ((end - start) / 3);
        int mid2 = start + 2 * ((end - start) / 3);

        sort(liste, start, mid1);
        sort(liste, mid1 + 1, mid2);
        sort(liste, mid2 + 1, end);
        merge(liste, start, mid1, mid2, end);
        return liste;
    }
}
