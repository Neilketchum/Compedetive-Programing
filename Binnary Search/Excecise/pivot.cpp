#include<bits/stdc++.h>
using namespace std;
int findMin(int *arr,int n ){
    int s = 0;
    int e = n-1;
     int pivot = -1;
     if(n == 1){
        return arr[0];
     }
     if(arr[0] < arr[n-1]){
         return arr[0];
     }
     
    while(s<=e){
        // cout<<s<<'\t'<<e<<endl;
        int mid = s + (e-s)/2;
        int prev = (mid-1+n)%n;
        int next = (mid + 1)%n;
       
        if(arr[mid]<arr[prev] && arr[mid] < arr[next]){
            pivot  = mid;
            return arr[mid];
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
int findMin_li(int *arr,int n){
    for(int i = 0;i<n;i++){
        if(arr[i] > arr[i+1]){
            return arr[i+1];
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
// {
//     int arr[] = {5,8,11,12,15,18,1,2};
//     int n = sizeof(arr)/sizeof(int);
 {
     int n ;
     cin>>n;
     int arr[n];
     for(int i =0;i<n;i++){
         cin>>arr[i];
     }
    cout<<findMin_li(arr,n);    
    return 0;
}
