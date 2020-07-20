#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll partition(ll *place,ll s ,ll e){
    ll i = s-1;
    ll j =s;
    for(;j<=e-1;){
        if(place[j] <= place[e]){
            i++;
            swap(place[i],place[j]);
        }
        j++;
    }
    swap(place[i+1],place[e]);
    return i+1;
}
void QuickSort(ll *place,ll s,ll e){
    if(s>= e){
        return;
    }
    ll p = partition(place,s,e);
    QuickSort(place,s,p-1);
    QuickSort(place,p+1,e);
}
int main(int argc, char const *argv[])
{
    ll t;
    cin>>t;
    while(t>0){
        ll n;
        cin>>n;
        string s[n];
        ll place[n];
        for(ll i =0;i<n;i++){
            cin>>s[i]>>place[i];
        }
        QuickSort(place,0,n-1);
        int badness = 0;
        for(int i = 0;i<n;i++){
            cout<<place[i]<<" "<<i<<endl;
            badness += abs(i-place[i]);
        }
    
        cout<<badness<<endl;
        t--;
}
   
    return 0;
}
