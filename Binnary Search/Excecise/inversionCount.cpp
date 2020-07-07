#include<bits/stdc++.h>
using namespace std;
#define ll long long 
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
int merge_sort(int *arr,int start,int end ){
    int s  = start;
    int e = end;
    if(s>=e){
        return 0;
    }
    int x = 0,y = 0,z = 0;
    // cout<<s<<'\t'<<e<<endl;
    int  mid = (s + e)/2;
    x += merge_sort(arr,s,mid);
    y += merge_sort(arr,mid + 1,e);
    z += merge(arr,s,e);

    return x+y+z;
}        
int main(int argc, char const *argv[])
{   
    int t;
    cin>>t;
    while(t> 0){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        // cout<<"main Test"<<endl;
        cout<<merge_sort(arr,0,n-1)<<endl;
        t--;
    }
    
    return 0;
}
