//Zhilin Li
//Csci 335
//Project 3
#include "QuickSelect2.hpp"
#include "InsertionSort.hpp"
//modify quickselect form textbook
//beside do quickselect 3 times, but one time and k become a vector
void quickSelect2 (const std::string & header, std::vector<int> data)
{
    int n = data.size();
    std::vector<int> k = {1,n/4,n/2,3*n/4,n};
    std::vector<int> result;
    result = quickselct2(data,k,0,n-1,result);
    std::cout<<header<<"\nMin: "<<result[0]<<"\nP25: "<<result[1]<<"\nP50: "<<result[2]<<"\nP75: "<<result[3]<<"\nMax: "<<result[4]<<"\n";
}

std::vector<int> quickselct2(std::vector<int> &data, std::vector<int> k, int left, int right, std::vector<int> &result)
{
    if(data.size()>20){
        //set middle be pivot and move it to the end
        std::swap(data[(left + right)/2],data[right]);
        //set the range of data exclude from pivot and let last become pivot 
        int i = left-1;
        int j = right;
        int pivot = data[right];
        //left_k store kths need be search on left of povit, and right_k is right side of poivt
        std::vector<int> left_k,right_k;
        for(;;)
        {
            //find first element that is smaller than povit
            while(data[++i]<pivot){}
            //find first element that is larger than povit
            while(data[--j]>pivot){}
            //if left and right mark don't meet swap, otherwise break
            if(i<j)
            {
                std::swap(data[i],data[j]);
            }
            else
            {
                break;
            }
        }
        //restore the povit
        std::swap(data[i],data[right]);
        for(std::vector<int>::iterator it = k.begin();it!=k.end();)
        {
            //check, either is find kth and push to result, or push to left_k or right_k
            if(*it == i+1)
            {
                result.push_back(data[i]);
                k.erase(it);
            }
            else if(i+1<*it)
            {
                right_k.push_back(*it);
                it++;
            }
            else if(i+1>*it)
            {
                left_k.push_back(*it);
                it++;
            }
            
        } 
        //recurison on left part and right of povit
        if(!left_k.empty())
        {
            quickselct2(data,left_k,left,i-1,result);
        }
        if(!right_k.empty())
        { 
            quickselct2(data,right_k,i+1,right,result);
        }

    }
    //if size of data less than 20 do insertion sort
    else
    {
        return insertionSort2(data,k);
    }
    return result;
}

std::vector<int> insertionSort2(std::vector<int> &data, std::vector<int> k)
{
    //insertion sort O(n^2)
    for(int i = 1; i< data.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(data[j]>data[i])
            {
                std::swap(data[j],data[i]);
            }
        }
    }
    //store all kths element to the result
    std::vector<int> result;
    for(int l = 0; l<k.size();l++)
    {
        result.push_back(data[k[l]-1]);
    }
    return result;
}
