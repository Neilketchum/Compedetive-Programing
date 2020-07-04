#include<bits/stdc++.h>
using namespace std;
int binary_search(int *arr,int n,int key){
    int s = 0;
    int e = n -1;
    while(s<=e){
        int mid = (s+e)/2;
        
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int arr[] = {19,21,33,49,51,63,72,84,99,103,212,280};
    int n = sizeof(arr)/sizeof(int);
    int key = 35;
    cout<<binary_search(arr,n,key)<<endl;   
    return 0;
}
