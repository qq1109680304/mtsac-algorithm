/*  Program: PA_12_exercise_1  
    Author: Nero Li
    Class: CSCI 220   
    Date: 11/23/2021	     
    Description: 
        Use your priority queue from exercise 1 to sort data in ascending order. Sort
        the data file small1k.txt, containing a list of 1,000 integer values, and output 
        the first 5 and last 5 values to the screen (5 values on one line and at least 
        one space between the 2 values). Sort the data file large100k.txt, containing 
        a list of 100,000 integer values, and output the first 5 and last 5 values to 
        the screen (5 values on one line and at least one space between the 2 values). 
        For each set of data, collect actual run times in milliseconds and display to 
        the screen as well.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "ListPriorityQueue.h"

using namespace std;

template <typename E>
class isLess 
{
public:
    bool operator()(const E& p, const E& q) const
    { 
        return p < q; 
    }
};

void func(string inputName, string outputName)
{
    ListPriorityQueue<int, isLess<int>> pq;
    ifstream fin;
    ofstream fout;
    int n{0};
    int i{0};

    fin.open(inputName, ios::binary);
    fout.open(outputName, ios::binary);

    auto start = chrono::high_resolution_clock::now();
    while (!fin.eof())
    {
        fin >> n;
        pq.insert(n);
    }

    n = pq.size();

    while (!pq.empty())
    {
        if (i < 5 || i > n - 6)
        {
            cout << pq.min() << ' ';
            fout << pq.min() << ' ';
        }
        if (i == 5 || i == n - 1)
        {
            cout << endl;
            fout << endl;
        }    
        ++i;
        pq.removeMin();
    }
    auto end = chrono::high_resolution_clock::now();
    cout << (chrono::duration_cast<chrono::nanoseconds>(end - start).count() * (double)1e-6) << " ms" << endl;
    fout << (chrono::duration_cast<chrono::nanoseconds>(end - start).count() * (double)1e-6) << " ms" << endl;
}

int main()
{
    func("small1k.txt", "small1k_output.txt");
    func("large100k.txt", "large100k_output.txt");

    cout << "Modified by: Nero Li\n";
    return 0;
}