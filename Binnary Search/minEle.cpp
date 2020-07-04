// Find the minimum elememt is rotated Sorted Array
#include<bits/stdc++.h>
using namespace std;
int minEleIndx(int *arr,int n){
    int s = 0;
    int e = n-1;
     int pivot = -1;
    while(s<=e){
        // cout<<s<<'\t'<<e<<endl;
        int mid = s + (e-s)/2;
        int prev = (mid-1+n)%n;
        int next = (mid + 1)%n;
       
        if(arr[mid]<arr[prev] && arr[mid] < arr[next]){
            pivot  = mid;
            return mid;
        }
        else if(arr[s] <= arr[mid]){
            s = mid+1;
        }else if(arr[mid] <= arr[e]){
			e = mid - 1;
		}
    }
    // if(arr[pivot] < arr[n-pivot]){

    // }
    return pivot;
}
int main(int argc, char const *argv[])
{
    int arr[] = {5,8,11,12,15,18,1,2};
    int n = sizeof(arr)/sizeof(int);
    cout<<minEleIndx(arr,n);    
    return 0;
}
