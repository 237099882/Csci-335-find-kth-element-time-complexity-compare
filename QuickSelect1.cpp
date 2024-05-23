//Zhilin Li
//Csci 335
//Project 3
#include "QuickSelect1.hpp"
#include "InsertionSort.hpp"
//modify quickselect form textbook
//call partition to find and print min, P25, P50，P75 and max
void quickSelect1 (const std::string & header, std::vector<int> data)
{
    //store the size of data into n
    int n = data.size();
    //use quickselect 3 times to find 25%, 50% and 75% tile
    int P50 = quickselct1(data, n*.5,0,n-1);
    int P25 = quickselct1(data, n*.25,0,n/2-1);
    int P75 = quickselct1(data, n*.75,n/2,n-1);
    //assume min is in index 0 and max is in last index
    int min = data[0];
    int max = data[data.size()-1];
    //for loop to find min below 25% tile and max above 75% tile
    for(int i = 0; i< data.size()/8;i++)
    {
        if(min>data[i])
        {
            min = data[i];
        }
    }
    for(int j = data.size()/4*3;j<data.size();j++)
    {
        if(max<data[j])
        {
            max = data[j];
        }
    }
    //print the result
    std::cout<<header<<"\nMin: "<<min<<"\nP25: "<<P25<<"\nP50: "<<P50<<"\nP75: "<<P75<<"\nMax: "<<max<<"\n";
}

int quickselct1(std::vector<int> &data, int k, int left, int right)
{
    //if size greater than 20
    if(data.size()>20){
        //set middle element be pivot and move it to the end
        std::swap(data[(left + right)/2],data[right]);
        //set the range of data exclude from pivot and let last become pivot 
        int i = left-1;
        int j = right;
        int pivot = data[right];

        for(;;)//O(n^2)
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
        //if index of kth element is equal to index povit + 1, return povit, otherwise decide to do quickselect either left or right part of povit 
        //O(1)
        if(k==i+1)
        {   
            return data[i];
        }
        else if(i+1<k)
        {
            left = i+1;
            quickselct1(data,k,left,right);
        }
        else if(i+1>k)
        {
            right = i-1;
            quickselct1(data,k,left,right);
        }
    }
    //else do an insertionsort
    else
    {
        return insertionSort(data,k);
    }
}

int insertionSort(std::vector<int> &data, int k)
{
    //use nest loop to sort the data
    for(int i = 1; i< data.size();i++)//O(n^2)
    {
        for(int j=0;j<i;j++)
        {
            if(data[j]>data[i])
            {
                std::swap(data[j],data[i]);
            }
        }
    }
    //return kth smallest element
    return data[k-1];
}
