#include <iostream>
#include <omp.h>

#include "filePro.cpp"
#include "include/sort_algos.hpp"

using namespace std;

int main()
{
    omp_set_num_threads(12); 
    //paralel: 248 saniye 4dk 8sn
    //normal:  630 saniye 10dk 30sn
    string path = "../data/";
    string paths[] = {"random", "reversed", "sorted"};
    string files[] = {"32K_string_1", "64K_string_1","128K_string_1"};

    int path_size = sizeof(paths) / sizeof(paths[0]);
    int file_size = sizeof(files) / sizeof(files[0]);
    vector<vector<string>> result;


    #pragma omp parallel for
    for (int i = 0; i < path_size; i++)
    {
        for (int j = 0; j < file_size; j++)
        {
            cout << "path: " << paths[i] << " file: " << files[j] << endl;
            vector<char> file = readFile(path + paths[i] + "/" + files[j]);
            for (int k = 0; k < 8; k++)
            {
                SType algoType = static_cast<SType>(k);
                vector<u_long> v= runAlgo(algoType, file);
                u_long time = v[0];
                u_long count = v[1];
                cout << time << count << " " << "algo type: " << getAlgoName(algoType) 
                    << " " << paths[i] << " " << files[j] << endl;
                result.push_back({to_string(time/1000000.0),to_string(count), getAlgoName(algoType), paths[i], files[j]});
            }
        }
    }

    generateCsvFile(result, "result.csv");
    return 0;
}