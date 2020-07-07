// Given number of pages in n different books and m students. The books are arranged in ascending order 
// of number of pages. Every student is assigned to read some consecutive books. The task is to 
// assign books in such a way that the maximum number of pages assigned to a student is minimum.
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
bool bookRakhPaye(ll *arr,ll n,ll m,ll min_page){
    ll studCount  =1;
    ll curr_pages = 0;
    for(ll i = 0 ;i<n;i++){
        if((curr_pages + arr[i]) > min_page ){
            studCount++;
            curr_pages = arr[i];
            if(studCount > m){
                return false;
            }
        }else{
            curr_pages += arr[i];
        }
    }
    return true;
}
ll findPages(ll *arr,ll n,ll m){
    ll sum = 0;
    for(ll i = 0;i<n;i++){
        sum+= arr[i];
    }
    ll s = 0;
    ll e = sum;
    ll ans = INT_MAX;
    while(s<=e){
        ll mid  = s  + (e - s)/2;
        if(bookRakhPaye(arr,n,m,mid)){
            
            ans = min(ans,mid);
            e = mid - 1;
        }else{
            s = mid+1;
        }
    }
    return ans;
}
int main() 
{ 
    //Number of pages in books 
    int n,m;
    cin>>n>>m;
    ll arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
  
    cout<< findPages(arr, n, m) << endl; 
    return 0; 
}