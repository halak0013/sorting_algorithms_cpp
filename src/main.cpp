#include <iostream>
#include <omp.h>

#include "filePro.cpp"
#include "include/sort_algos.hpp"

using namespace std;

int main()
{
    //omp_set_num_threads(12);
    string path = "../data/";
    string paths[] = {"random", "reversed", "sorted"};
    string files[] = {"32K_string_1", "64K_string_1"};

    int path_size = sizeof(paths) / sizeof(paths[0]);
    int file_size = sizeof(files) / sizeof(files[0]);
    vector<vector<string>> result;


    //#pragma omp parallel for
    for (int i = 0; i < path_size; i++)
    {
        for (int j = 0; j < file_size; j++)
        {
            cout << "path: " << paths[i] << " file: " << files[j] << endl;
            vector<char> file = readFile(path + paths[i] + "/" + files[j]);
            for (int k = 0; k < 8; k++)
            {
                SType algoType = static_cast<SType>(k);
                vector<double> v= runAlgo(algoType, file);
                double time = v[0];
                double count = v[1];
                cout << time << count << " " << "algo type: " << algoType 
                    << " " << paths[i] << " " << files[j] << endl;
                result.push_back({to_string(time),to_string(count), to_string(algoType), paths[i], files[j]});
            }
        }
    }

    generateCsvFile(result, "result.csv");
    return 0;
}