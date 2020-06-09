// Coupon Collector problem Based Problem
// What is the xpected number of throws reqd to get all the sides of the die .SIdes of the dice is n;
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    int n;
    double ans;
    while(t>0){
        ans = 0.0;
        cin>>n;
        for(int i =1;i<=n;i++){
                ans+= n/(i * 1.0);
          }     
        cout<<fixed<<setprecision(2)<<ans<<endl;
        t--;
    }
    return 0;
}

