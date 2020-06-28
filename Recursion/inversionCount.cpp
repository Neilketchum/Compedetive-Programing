// // Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.
// // Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
// Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.
// Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
// METHOD 1 (Simple)

// Approach :Traverse through the array and for every index find the number of smaller elements on its right side of the array. This can be done using a nested loop. Sum up the counts for all index in the array and print the sum.

#include<bits/stdc++.h>
using namespace std;
void getInvCountNaive(int *arr,int n){

    int inv_count = 0;
    for(int i =0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(arr[i] > arr[j]){
                inv_count++;
                cout<<"("<<arr[i]<<","<<arr[j]<<")"<<"\t";
            }
        }
    }
    cout<<"\n"<<inv_count<<endl;
}
int merge(int *a,int s,int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;  
    int temp[100000];
    int cnt = 0;
    while(i<=mid and j<=e){
        if(a[i]<=a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++]  = a[j++];
            cnt += mid -i + 1 ;
        }
    }
    //filling the leftovers
    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=e){
        temp[k++] = a[j++];
    }
    for(int i = s;i <= e;i++){
        a[i] = temp[i];
    }
    return cnt;
}
int inv_count(int *arr,int s,int e){
    if(s>=e){
        return 0;
    }
    int mid = (s+e)/2;
    int x = inv_count(arr,s,mid);
    int y = inv_count(arr,mid+1,e);
    int z = merge(arr,s,e);
    return x + y + z;
}
int main(int argc, char const *argv[])
{
    int arr[]= {1,5,2,6,3,0};
    // getInvCountNaive(arr,4);
    int n = sizeof(arr)/sizeof(int);
    cout<<inv_count(arr,0,n-1)<<endl;
    return 0;
}
