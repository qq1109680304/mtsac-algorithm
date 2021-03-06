/*  Program: PA_#_exercise_2  
    Author: Nero Li
    Class: CSCI 230   
    Date: MM/DD/2022	     
    Description: 
        ----------------------------------------------------------------

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int BUFFER_SIZE{4000};

void seperateFile(string str)
{
    ifstream fin;
    fin.open(str, ios::binary);
    
    if (!fin)
    {
        cout << "File error\n";
        return;
    }
    
    fin.seekg(0, ios::end);
    int totalNum = fin.tellg() / sizeof(int);
    char fileBuffer[sizeof(int)];
    fin.close();

    fin.open(str, ios::binary);
    ofstream fout;
    fout.open("firstHalf.bin", ios::binary);
    for (int i = 0; i <= totalNum / 2; ++i)
    {
        fin.read(fileBuffer, sizeof(int));
        if (fin.gcount() != 0)
            fout.write(fileBuffer, sizeof(int));
    }
    fout.close();

    fout.open("secondHalf.bin", ios::binary);
    for (int i = 0; i <= totalNum / 2; ++i)
    {
        fin.read(fileBuffer, sizeof(int));
        if (fin.gcount() != 0)
            fout.write(fileBuffer, sizeof(int));
    }
    fout.close();
    fin.close(); 
}

void sortFile(string str)
{
    ifstream fin;
    ofstream fout;
    vector<int> vec;

    fin.open(str, ios::binary);
    int value = 0;
    fin.read(reinterpret_cast<char*>(&value), sizeof(int));
    while (fin.gcount() != 0)
    {
        vec.push_back(value);
        fin.read(reinterpret_cast<char*>(&value), sizeof(int));
    }
    fin.close();

    sort(vec.begin(), vec.end());

    fout.open(str, ios::binary);
    fout.clear();
    for (int i : vec)
        fout.write(reinterpret_cast<char*>(&i), sizeof(int));
    fout.close();
}

void printFinalResult(string str)
{
    vector<int> vec;
    ifstream file;
    file.open(str, ios::binary);
    
    if (!file)
    {
        cout << "err\n";
        return;
    }
    file.seekg(0, ios::end);
    int totalNum = file.tellg() / sizeof(int);
    file.close();

    file.open(str, ios::binary);

    int value = 0;
    file.read(reinterpret_cast<char*>(&value), sizeof(int));
    while (file.gcount() != 0)
    {
        vec.push_back(value);
        file.read(reinterpret_cast<char*>(&value), sizeof(int));
    }

    for (int i = 1; i <= vec.size(); ++i)
        if (i <= 5 || i > vec.size() - 5)
            cout << "vec[" << i - 1 << "] = " << vec[i - 1] << endl;
    
}

int main()
{
    seperateFile("filetoSort.bin");
    sortFile("filetoSort.bin");
    printFinalResult("result.bin");

    cout << "Author: Nero Li\n";

    return 0;
}
