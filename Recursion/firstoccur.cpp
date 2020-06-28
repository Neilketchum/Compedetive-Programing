#include<bits/stdc++.h>
using namespace std;
// int firstOccur(int *arr,int n,int key){
//     if(n == 0){
//         return -1;
//     }
//     if(arr[0] == key){
//         return n;
//     }else{
//         return firstOccur(arr+1,n-1,key);
//     }
// }
// int depth  = -1;
// int lastOccur(int *arr,int n,int key){
//     if(n == 0){
//         return depth;
//     }
//     if(arr[0] ==key){
//         depth = n;
//     }
//     else{
//          lastOccur(arr+1,n-1,key);
//     }
// }
int firstOccur(int *a,int n,int key){
    if(n == 0){
        return -1;
    }
    if(a[0] == key){
        return 0;
    }
    int i = firstOccur(a+1,n-1,key);
    if(i == -1){
        return -1;
    }
    else{
        return i+1;
    }
}
int firstOccur_1(int *a,int i,int n,int key){
    if(i == n){
        return -1;
    }
    if(a[i] == key){
        return i;
    }
    return firstOccur_1(a,i+1,n,key);
}
int lastOccur(int *a,int n,int key ){
    if(n == 0){
        return -1;
    }
    int i = lastOccur(a+1,n-1,key);
    if(i == -1){
        if(a[0] == key){
            return 0;
        }else{
            return -1;
        }
    }
    // if i returned is not -1;
    return i + 1;
}
int main(){
    int arr[] = {1,2,3,7,4,5,6,7,10,12,18,21};
    int key;
    int size = sizeof(arr)/sizeof(int);
    cin>>key;
    cout<< firstOccur(arr,size,key)<<endl;
    cout<<firstOccur_1(arr,0,size,key)<<endl;
    cout<<lastOccur(arr,sizeof(arr),key)<<endl;
}