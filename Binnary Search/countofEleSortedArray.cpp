#include<bits/stdc++.h>
using namespace std;
int getFirst(int *arr,int n,int key){
    int s = 0;
    int e = n-1;
    int firstOccur = -1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid] == key){
            firstOccur  = mid;
            e = mid -1;
        }
        else if(key > arr[mid]){
            s = mid+1;
        }
        else{
            e = mid -1;
        }
    }
    return firstOccur;
}
int getLast(int *arr,int n,int key){
    int s = 0;
    int e = n-1;
    int lastOccur = -1;
    while(s <= e){
        int mid = s + (e-s)/2;
        if(arr[mid] == key){
            lastOccur = mid;
            s = mid+1;
        } 
        else if(arr[mid] > key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return lastOccur;
}

int main(int argc, char const *argv[])
{
     int arr[] = {2,4,5,6,10,10,10,10,10,10,10,18,20};
    int n = sizeof(arr)/sizeof(int);
    int key = 10;
    cout<<getFirst(arr,n,key)<<endl;
    cout<<getLast(arr,n,key)<<endl;
    cout<<"Total Freq "<<getLast(arr,n,key) - getFirst(arr,n,key) +1<<endl;
    return 0;
}
