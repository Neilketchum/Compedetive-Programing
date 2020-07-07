#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll binarySearch(ll *arr,ll start,ll n,ll key){
    ll s = start;
    ll e = n-1;
    while(s<=e){
        ll mid = (s + e)/2;
        if(arr[mid] == key){
            // cout<<"Got "<<mid<<endl;
            return mid;
        }
        if(arr[mid] > key){
            e = mid -1;
        }else if(arr[mid] < key){
            s = mid +1;
        }
    }
    return -1;
}
ll getMinele(ll *a,ll n){
    ll s = 0;
    ll e = n -1;
    if(a[0] < a[e]){
        return 0;
    }
    while(s <= e){
        ll mid = s + (e-s)/2;
        ll prev = (mid - 1 + n) %n;
        ll next = (mid + 1)%n;
        if(a[mid] < a[next] && a[mid]<a[prev]){
            // cout<<mid<<"a"<<endl;
            return mid;
        }
        if(a[s] <= a[mid]){
            s = mid+1;
        }
        if(a[mid] <= a[e]){
            e = mid -1;
        }
    }
	return 1;
}
int main(int argc, char const *argv[])
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i = 0;i<n;i++){
        cin>>arr[i];
    }
    ll key;
    // cout<<endl;
    ll p = getMinele(arr,n);
    // cout<<p<<endl;
    cin>>key;
    ll l = binarySearch(arr,0,p,key);
	ll r = binarySearch(arr,p+1,n,key);
    if(l != -1){
        cout<<l<<endl;
    }
    else if(r!=-1){
        cout<<r<<endl;
    }
    else{
        cout<<-1<<endl;
    }
  
    return 0;
}