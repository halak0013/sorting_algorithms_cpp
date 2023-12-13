#ifndef MERGESORT3_HPP
#define MERGESORT3_HPP
#include <vector>
#include <iostream>
using namespace std;

//https://gist.github.com/Akohrr/4dfd2cd4df43489269a30abce9044120
class MergeSort3
{
private:
    vector<char> list;
    vector<char> sort(vector<char> &liste, int start, int end);


public:
    
    MergeSort3(vector<char> listToSort);
    vector<char> sort(vector<char>);
    void merge(vector<char> &liste,int s, int mid1, int mid2, int end);
    int c=0;
};
#endif // MERGESORT3_HPP