#include<bits/stdc++.h>
using namespace std;
bool canPaint(int *arr,int n,int k,int min_time){
    int time = 0;
    int painter = 1;
    int to_paint= 0;
    for(int i =0;i<n;i++){
        to_paint+=arr[i];
    }
    int i = 0;
    while(i<n){
        if((time + arr[i] )<= min_time ){
            time += arr[i];
            to_paint -= arr[i];
            i++;
        }
        else{
            time   = 0;
            painter++;
        }
    }
    cout<<" Value of n "<<n<<"Value k = "<<k<<" Painter "<<painter<<" Min Time "<<min_time<<" To Paint "<<to_paint<<endl;
    if(painter <= k && to_paint == 0 ){
        return true;
    }else{
        return false;
    }
}
int partition(int *arr,int n,int k){
    int s  = arr[0];
    int  time = 0;
    for(int i = 0;i<n;i++){
        time+=arr[i];
    }
    int e = time;
    int result = -1;
    while(s<=e){
        int mid = s + (e-s)/2;
   
        if(canPaint(arr,n,k,mid)){

            result = mid;
            e = mid-1;
        }else{

            s = mid +1;
        }
    }
    return result;
}
int main(int argc, char const *argv[])
{   
    int n,k;
    cin>>k;
    cin>>n;
    int a[n] = {0};
    for(int  i = 0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    // cout<<a[0]<<endl;
    cout<<partition(a,n,k)<<endl;
    return 0;
}
