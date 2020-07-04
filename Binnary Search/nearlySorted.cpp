// // Given an array which is sorted, but after sorting some elements are
//  moved to either of the adjacent positions, i.e., arr[i] may be present 
//  at arr[i+1] or arr[i-1]. Write an efficient function to search an element
//   in this array. Basically the element arr[i] can only be swapped with either arr[i+1] or arr[i-1].
#include<bits/stdc++.h>
using namespace std;
int nearlySorted(int *arr,int n,int key){
    int s = 0;
    int e = n-1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid-1] == key){
            return mid-1;
        }
        if(arr[mid+1] == key){
            return mid+1;
        }
        if(key > arr[mid]){
            s = mid+2;
        }else{
            e = mid -2;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{     
    int  arr[] =  {10, 3, 40, 20, 50, 80, 70};

    int n = sizeof(arr)/sizeof(int);
    cout<<nearlySorted(arr,n,80);
    int arr1[] =  {10, 3, 40, 20, 50, 80, 70};
     n = sizeof(arr1)/sizeof(int);
    cout<<nearlySorted(arr1,n,90);
    return 0;
}
