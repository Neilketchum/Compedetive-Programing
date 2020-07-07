#include <bits/stdc++.h>
using namespace std;
int binnarySearch(int *arr,int s,int n,int key){
    int e = n-1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid] > key ){
            e = mid -1;
        }
        else if(arr[mid]  < key){
            s = mid+1;
        }
    }
    return -1;
}
int search(int *arr, int n, int key)
{
    int s = 0;
    int e = n - 1;
    int pivot = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        int next = (mid+1)%n;
        int prev   = (mid -1)%n;

        if (arr[mid] < arr[prev] && arr[mid] < arr[next])
        {
            pivot = mid;
            break;
        }else if(arr[s] <= arr[mid]){
            s = mid +1;
        }else if(arr[mid] <= arr[e]){
            e = mid -1;
        }
    }
    int first = binnarySearch(arr,0,pivot,key);
    int second = binnarySearch(arr,pivot+1,n,key);
    if(first == -1 && second == -1){
        return -1;
    }
    else if(first !=-1){
        return first;
    }else{
        return second;
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {5, 6, 7,8,9,10,11,12,13,14,15, 1, 2, 3,4};
    int n = sizeof(arr) / sizeof(int);
    int key = 12;
    cout << search(arr, n, key) <<endl;
    return 0;
}

