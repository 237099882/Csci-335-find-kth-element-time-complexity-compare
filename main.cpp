//Zhilin Li
//Csci 335
//Project 3
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "StdSort.hpp"
#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "CountingSort.hpp"
#include <chrono>

int main ()
{
    std::string filename = "test_input3.txt";
    std::ifstream fin(filename);
    std::string header;
    std::getline(fin,header);
    std::string temp;
    std::getline(fin,temp);
    std::stringstream ss(temp);
    std::string data;
    std::vector<int> datas;
    while(ss>>data)
    {
        datas.push_back(stoi(data));
    }
    auto start1 = std::chrono::high_resolution_clock::now();
    stdSort(header,datas);
    auto stop1 = std::chrono::high_resolution_clock::now();
    std::cout<<std::endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    quickSelect1(header,datas);
    auto stop2 = std::chrono::high_resolution_clock::now();
    std::cout<<std::endl;
    auto start3 = std::chrono::high_resolution_clock::now();
    quickSelect2(header,datas);
    auto stop3 = std::chrono::high_resolution_clock::now();
    std::cout<<std::endl;
    auto start4 = std::chrono::high_resolution_clock::now();
    countingSort(header,datas);
    auto stop4 = std::chrono::high_resolution_clock::now();
    std::cout<<std::endl;
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);
    auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(stop3 - start3);
    auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(stop4 - start4);

    std::cout<<duration1.count()<<" "<<duration2.count()<<" "<<duration3.count()<<" "<<duration4.count()<<std::endl;
    return 0;
}
