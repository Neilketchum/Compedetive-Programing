#include<bits/stdc++.h>
using namespace std;
void merge(int *a,int s,int e){
    int i =  s;
    int mid = (s+e)/2;
    int j = mid + 1;
    int k = s;
    int temp[100] = {0};
    while(i<=mid and j<=e ){
        if(a[i] < a[j]){
            temp[k] = a[i];
            i++;
            k++;
        }else{
            temp[k] = a[j];
            j++;
            k++;
        }
       
    }
    while(i<=mid){
        temp[k] = a[i];
        i++;
        k++;
    }
    while(j<=e){
        temp[k] = a[j];
        j++;
        k++;
    }
    // Coypping temp into original a;
    for(int i =s;i<=e;i++){
        a[i] = temp[i];
    }
}
void mergeSort(int *a,int s,int e){
    //Base Case
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    // Dividing all arays;
    mergeSort(a,0,mid);
    mergeSort(a,mid+1,e);
    // Merging
    merge(a,s,e);
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,6,1,2,4,0};
    int size = sizeof(arr)/sizeof(int);
    mergeSort(arr,0,5);
    for(auto x:arr){
        cout<<x<<"\t";
    }
    return 0;
}
