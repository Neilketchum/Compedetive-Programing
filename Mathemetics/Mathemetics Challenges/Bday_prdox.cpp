// Your task is simple, determine the minimum number of people required in the room so that two have same birthday with 
// probability greater than or equal to 'p'. (Assume there are 365 days in every year)
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    double s,f,x = 1.0;
    cin>>s;
    f = 1 -s;
    int numer = 365,denom = 365; 
    int person = 0;

    while(x > f){
        x = x * numer/denom;
        numer--;
        person++;
    }
    cout<<person<<endl;
    return 0;
}
