//Zhilin Li
//Csci 335
//Project 3
#include "StdSort.hpp"
//sort the vector and print min, P25, P50，P75 and max
void stdSort (const std::string & header, std::vector<int> data)
{
    std::sort(data.begin(),data.end());//O(nlogn)
    //below is O(1)
    int min = data.front();
    int P25 = data.at(data.size()*.25-1);
    int P50 = data.at(data.size()*.5-1);
    int P75 = data.at(data.size()*.75-1);
    int max = data.back();
    std::cout<<header<<"\nMin: "<<min<<"\nP25: "<<P25<<"\nP50: "<<P50<<"\nP75: "<<P75<<"\nMax: "<<max<<"\n";
}