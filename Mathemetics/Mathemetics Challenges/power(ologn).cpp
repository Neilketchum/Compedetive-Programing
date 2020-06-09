#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll pow(ll x,ll n){
	if(n == 0){
		return 1;
	}
	if(n == 1){
		return x;
	}
	if(n&1){
		return x * pow(x,n/2) * pow(x,n/2);
	}else{
		return pow(x,n/2) * pow(x,n/2);
	}
}
int main(){
	ll n,p;
	cin>>n>>p;
	cout<<pow(n,p)<<endl;
}