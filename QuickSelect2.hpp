//Zhilin Li
//Csci 335
//Project 3
#ifndef QUICKSORT2_HPP
#define QUICKSORT2_HPP
#include <iostream>
#include <vector>
#include <algorithm>
void quickSelect2 (const std::string & header, std::vector<int> data);
std::vector<int> quickselct2(std::vector<int> &data, std::vector<int> k, int left, int right, std::vector<int> &result);
std::vector<int> insertionSort2(std::vector<int> &data, std::vector<int> k);
#endif