#include <iostream>

using namespace std;

void merge(int *arr, int s, int e)
{
    // code of creating two arrays which are sorted
    int mid = (s+e)/2;
    
    int len1 = mid - s + 1;
    int len2 = e - mid;
    
    int *first = new int[len1];
    int *second = new int[len2];
    
    // copy values
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }
    
    mainArrayIndex = mid + 1;
    for(int i=0; i<len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }
    
    // code of merging of sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;
    
    while(index1 < len1 && index2 < len2)
    {
        if(first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }
    
    while(index1 < len1)          // if element in arr1 is more
    {
        arr[mainArrayIndex++] = first[index1++];
    }
    
    while(index2 < len2)            // if element in arr2 is more
    {
        arr[mainArrayIndex++] = second[index2++];
    }
    
}

void mergeSort(int *arr, int s, int e)
{
    // base case
    if(s >= e)
    {
        return;
    }
    
    int mid = (s+e)/2;
    
    // left part sort karna h
    
    mergeSort(arr, s, mid);
    
    // right part sort karna right
    mergeSort(arr, mid+1, e);
    
    // merge left sorted part with right sorted part
    merge(arr, s, e);
}

int main()
{
    int arr[10] = { 3,7,0,1,5,9,3,2,35,66};
    int n = 10;
    mergeSort(arr, 0, n-1);
    
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;
}