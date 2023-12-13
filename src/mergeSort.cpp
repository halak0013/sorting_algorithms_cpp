#include "include/mergeSort.hpp"

MergeSort::MergeSort(vector<char> listToSort) : list(listToSort) {}

vector<char> MergeSort::getList()
{
    return list;
}

void MergeSort::sort()
{
    list = sort(list);
}

vector<char> MergeSort::sort(vector<char> whole)
{
    if (whole.size() == 1)
    {
        return whole;
    }
    else
    {
        vector<char> left(whole.begin(), whole.begin() + whole.size() / 2);
        vector<char> right(whole.begin() + whole.size() / 2, whole.end());

        left = sort(left);
        right = sort(right);

        merge(left, right, whole);

        return whole;
    }
}

void MergeSort::merge(vector<char> &left, vector<char> &right, vector<char> &result)
{
    int x = 0;
    int y = 0;
    int k = 0;

    while (x < left.size() && y < right.size())
    {
        c++;
        if (left[x] < right[y])
        {
            result[k] = left[x];
            x++;
        }
        else
        {
            result[k] = right[y];
            y++;
        }
        k++;
    }

    vector<char> rest;
    int restIndex;
    if (x >= left.size())
    {
        rest = right;
        restIndex = y;
    }
    else
    {
        rest = left;
        restIndex = x;
    }

    for (int i = restIndex; i < rest.size(); i++)
    {
        result[k] = rest[i];
        k++;
    }
}
