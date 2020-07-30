#include<bits/stdc++.h>
using namespace std;
int maxWine(int *wines,int s,int e,int years){
        if(s>e){
            return 0;
        }
        int opt1 = maxWine(wines,s+1,e,years+1) + wines[s]*years;
        int opt2 = maxWine(wines,s,e-1,years+1) + wines[e]*years;
        return max(opt1,opt2);
}
int main(int argc, char const *argv[])
{
    int wines[5] = {2,3,5,1,4};
    int k = sizeof(wines)/sizeof(int);
    cout<<maxWine(wines,0,k-1,1)<<endl;     
    return 0;
}
