#include<bits/stdc++.h>
using namespace std;
void allOcc(int *a,int n,int key){
    if(i == n){
        return ;
    }
    if(a[i] == key){
        cout<<i<<"\t";
    }
    allOcc(a+1,n,key);
}

int main(){
    int arr[] = {1,2,3,7,4,5,6,7,10,12,18,21};
    int key;
    int size = sizeof(arr)/sizeof(int);
    cin>>key;
    allOcc(arr,size,key);
    int output[100];
    int cnt = storealoc(arr)
}