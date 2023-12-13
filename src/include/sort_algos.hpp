#include <iostream>
#include <vector>
#include <chrono>
#include "../common.cpp"
#include "mergeSort.hpp"
#include "mergeSort3.hpp"
#include "quickSort.hpp"
#include "heapSort.hpp"

using namespace std;

std::vector<double> runAlgo(SType, vector<char>);
int heapSort(vector<char>);
int quickSortLH(vector<char>, bool);
int mergeSort(vector<char>);
int mergeSort3(vector<char> i_a);
int shellSort(vector<char>);
int insertionSort(vector<char> i_a);
int sellectionSort(vector<char> i_a);
void print(vector<char> i_a);