// What is the minimum num of ppl that should be present in a hall
// so there is a 50% chance of atleast two people having the same bday
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    float x = 1.0;
    int person = 0;
    int num = 365,denom=365;
    cout<<"Enter Probablity"<<endl;
    float p;
    cin>>p;
    if(p = 1){
        cout<<366<<endl;
        return 0;
    }
    while(x > 1-p){
        x = x*(num)/denom;
        num--;
        cout<<"probablity  = "<<x<<" Person"<<person<<endl;
        person++;
    }
    cout<<endl;
    cout<<person;
    return 0;
}
