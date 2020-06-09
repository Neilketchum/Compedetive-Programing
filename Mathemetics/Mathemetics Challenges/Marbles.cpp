// https://www.spoj.com/problems/MARBLES/
// Stars and Bars Problem
// Using a method that's often called "stars and bars":
// We draw n
// stars in a row to represent the cakes, and k−1 bars to divide them up. All of the stars to the
//  left of the first bar are cakes of the first type; stars between the first two bars are of the second type; 
 
// **|***||*|
// Here's an example with n=6
// and k=5. We're getting 2 of the first type, 3 of the second type, 0
//  of the third type, 1 of the fourth type, and 0 of the fifth type.
// In order to solve the problem, we just need to reorder the stars and bars by choosing the k−1
// spots for the bars out of the n+k−1 total spots, so our answer is:

// (n+k−1k−1)

// ((n-k)+k-1)C(k-1) =>  (n-1)C(k-1)  
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fact(ll n){
    ll result = 1;
    for(ll i = n;i > 1;i--){
        
        result = result * i;
       
    }

    return result;
}
int combination(ll n,ll r){
    if(n == r){
        return 1;
    }
    ll numer = 1;
    for(ll i = 0;i<  r;i++){
        numer = numer * (n-i);
    }
    ll result = numer/fact(r);
    return result;
}
int main(int argc, char const *argv[])
{
    int t;
    ll n,r;
    cin>>t;
    while(t>0){
        cin>>n>>r;
        cout<<combination(n-1,r-1)<<endl;
        t--;
    }
    return 0;
}
