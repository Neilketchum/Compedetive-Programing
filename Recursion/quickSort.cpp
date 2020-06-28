#include<bits/stdc++.h>
using namespace std;
int partition(int *a,int s,int e){
    int i = s - 1 ;
    int j = s;
    int pivot = a[e];
    for(;j<=e-1;){
        if(a[j]<= pivot){
            // MErge Smaller Part in region-1
            i++;
            swap(a[i],a[j]);
        }
        j = j + 1;
    }
    // Fixing The Pivot
    swap(a[i+1],a[e]);
    return i+1;
}

void quickSort(int *arr,int s,int e){

    if(s>=e){
        return;
    }
    int p =partition(arr,s,e);
    
    quickSort(arr,s,p-1);

    quickSort(arr,p+1,e);

}



int main(int argc, char const *argv[])
{
    int arr[] = {2,7,8,6,1,5,4};
    int n =sizeof(arr)/sizeof(int);
    quickSort(arr,0,n-1);
    for(auto x:arr){
        cout<<x<<"\t";
    }
    cout<<endl;
    return 0;
}
