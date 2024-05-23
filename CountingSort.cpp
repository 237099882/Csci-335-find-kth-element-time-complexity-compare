//Zhilin Li
//Csci 335
//Project 3
#include "CountingSort.hpp"

void countingSort (const std::string & header, std::vector<int> data)
{
    //if element exist increament the count
    //otherwise create a new element with count 1
    std::unordered_map<int,int> pairs;
    for(auto it : data)//O(n)
    {
        if(pairs.count(it))
        {
            pairs[it]++;
        }
        else
        {
            pairs.insert({it,1});
        }
    }
    //insert everything to a vector and sort it 
    std::vector<int> sorted;
    for(auto it : pairs)//O(k), k is number of unique value
    {
        sorted.push_back(it.first);
    }
    std::sort(sorted.begin(),sorted.end());//O(klogk)
    //find element of min, 25%, 50%, 75% and max.
    int min = sorted.front();
    int max = sorted.back();
    int size = data.size();
    int P25,P50,P75;
    int start = 0;
    int end = -1;
    //iterate map and if index of duplicate of range of counting array include the percent tail, set to element 
    //the unique valye is size of unorder map
    int unique_value = sorted.size();
    //find 25, 50 and 75 percent tile
    for(std::vector<int>::iterator it = sorted.begin();it!=sorted.end();++it)
    {   
        //let start become next index of last element
        start = end+1;
        //let end become end tail of range of a number of duplicate of this element
        end = start + pairs[*it]-1;
        //if percent tail is fall into the range, set the percent tail
        if(start<=size*.25-1&&end>=size*.25-1)
        {
            P25 = *it;
        }
        if(start<=size*.5-1&&end>=size*.5-1)
        {
            P50 = *it;
        }
        if(start<=size*.75-1&&end>=size*.75-1)
        {
            P75 = *it;
        }        
    }
    std::cout<<header<<"\nMin: "<<min<<"\nP25: "<<P25<<"\nP50: "<<P50<<"\nP75: "<<P75<<"\nMax: "<<max<<"\n"<<"Unique: "<<unique_value<<"\n";
}