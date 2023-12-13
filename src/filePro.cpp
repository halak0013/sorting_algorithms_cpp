#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<char> readFile(const string &filePath)
{
    ifstream file(filePath, ios::binary | ios::ate);
    if (!file.is_open())
    {
        cerr << "Failed to open file: " << filePath << endl;
        return {};
    }

    streamsize size = file.tellg();
    file.seekg(0, ios::beg);

    vector<char> buffer(size);
    if (!file.read(buffer.data(), size))
    {
        cerr << "Failed to read file: " << filePath << endl;
        return {};
    }

    return buffer;
}

void generateCsvFile(const vector<vector<string>> &data, const string &filePath)
{
    ofstream file(filePath);
    if (!file.is_open())
    {
        cerr << "Failed to open file: " << filePath << endl;
        return;
    }

    for (const vector<string> &line : data)
    {
        for (size_t i = 0; i < line.size(); ++i)
        {
            file << line[i];
            if (i != line.size() - 1)
                file << ",";
        }
        file << "\n";
    }
    file.close();
}
