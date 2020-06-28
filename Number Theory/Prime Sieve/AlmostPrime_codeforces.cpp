#include<bits/stdc++.h>
using namespace std;
void sieve(int *p,int max_range ){
    for(int i = 2;i<max_range;i=i+2){
        p[i] = 1; //Marking all  as even no as 1 divsiors 
    }
    for(int i = 3;i<max_range;i++){
        if(p[i] == 0){
            // cout<<i<<endl;
            for(int j = i;j<max_range;j = j+i){
                p[j]++;
            }
        }
    }
    // for(int i = 0;i<max_range;i++){
    //     cout<<p[i]<<"\t";
    // }
}
int count(int *p,int n){
    int count = 0;
    for(int i =0;i<=n;i++){
        if(p[i] == 2)
            count++;
    }
    return count;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int p[n+5] = {0};
    sieve(p,n+5);
    cout<<count(p,n)<<endl;
    return 0;
}



