#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool ms(string a,string b,ll s1,ll s2,ll e1,ll e2){
    if(s1>e1 || s2>e2)
        return false;
        ll  index=s2;
    for(ll i=s1;i<=e1;i++){
        if(a[i]!=b[index]){
            index=-1;
            break;
        }
        index++;
    }
    if(index!=-1)
        return true;
    if((e1-s1+1)%2==1 || (e2-s2+1)%2==1){
        return false;
    }
    ll mid1=(s1+e1)/2;
    ll mid2=(s2+e2)/2;
    return (ms(a,b,s1,s2,mid1,mid2)&& ms(a,b,mid1+1,mid2+1,e1,e2))||(ms(a,b,s1,mid2+1,mid1,e2)&& ms(a,b,mid1+1,s2,e1,mid2));
 
}
bool solve(string a,string b,ll s1,ll s2,ll e1,ll e2){
    ll  mid=(s1+e1)/2;
    return (ms(a,b,s1,s2,mid,mid)&& ms(a,b,mid+1,mid+1,e1,e2))||(ms(a,b,s1,mid+1,mid,e2)&& ms(a,b,mid+1,s2,e1,mid));
 
}
int main(){
        int t;
        cin>>t;
        while(t> 0){
             string a,b;
        cin>>a>>b;
        if(a==b)
            cout<<"YES\n";
        else{
            ll l1=a.length();
            ll l2=b.length();
            if(l1!=l2){
                cout<<"NO\n";
            }
            else{
                if(l1%2==1)
                    cout<<"NO\n";
                else if(solve(a,b,0,0,l1-1,l2-1)){
                    cout<<"YES\n";
                }
                else{
                    cout<<"NO\n";
                }
            }
        }


            t--;
        }
       
 
    return 0;
}