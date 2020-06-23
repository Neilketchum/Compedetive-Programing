#include<bits/stdc++.h>
using namespace std;

int partition(int *a,int s ,int e){

    int i = s-1;
    int j = s;
    int pivot = a[e];
    for(;j<=e-1;){
        if(a[j] <= a[e]){
            i++;
            swap(a[i],a[j]);
        }
        j++;
    }
    swap(a[i+1],a[e]);
    return i + 1;
}
void quickSort(int *arr,int s,int e){
    if(s>=e){
        return;
    }
    int p = partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}
int main(int argc, char const *argv[])
{
    int arr[] = {2,4,1,3,7,10,23,1,234,9};
    int size = sizeof(arr)/sizeof(int);
    quickSort(arr,0,size-1);
    for(auto x:arr){
        cout<<x<<"\t";
    }
    cout<<endl;
    return 0;
}
