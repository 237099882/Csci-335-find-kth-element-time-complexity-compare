//Zhilin Li
//Csci 335
//Project 3
#ifndef QUICKSORT1_HPP
#define QUICKSORT1_HPP
#include <iostream>
#include <vector>
#include <algorithm>
//call quickselect 3 timesto find and print min, P25, P50，P75 and max
void quickSelect1 (const std::string & header, std::vector<int> data);
//find kth smallest element and return it
int quickselct1(std::vector<int> &data, int k, int left, int right);
//if data size less than 20, call an insertion to find min, P25, P50，P75 and max  
int insertionSort(std::vector<int> &data, int k);
#endif