#include <iostream>
#include <vector>
#include <chrono>
#include "../common.cpp"
#include "mergeSort.hpp"
#include "mergeSort3.hpp"
#include "quickSort.hpp"
#include "heapSort.hpp"

using namespace std;
typedef unsigned long u_long;

std::vector<u_long> runAlgo(SType, vector<char>);
u_long heapSort(vector<char>);
u_long quickSortLH(vector<char>, bool);
u_long mergeSort(vector<char>);
u_long mergeSort3(vector<char> i_a);
u_long shellSort(vector<char>);
u_long insertionSort(vector<char> i_a);
u_long sellectionSort(vector<char> i_a);
void print(vector<char> i_a);
std::string getAlgoName(SType type);