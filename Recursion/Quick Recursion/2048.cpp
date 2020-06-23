// 2048 -> two zero four eight
#include<bits/stdc++.h>
using namespace std;
char words[][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
void printSpellings(int n){

    // Base Case
    if(n == 0){
        return;
    }
    printSpellings(n/10);
    
    int digit = n% 10;
    cout<<words[digit]<<" ";
}
int main(int argc, char const *argv[])
{
    int n ;
    cin>>n;
    if(n == 0){
        return 0;
    }
    printSpellings(n);
    return 0;
}
