// Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
// The output strings should be printed in the sorted order considering '(' has higher value than ')'.


#include<bits/stdc++.h>
using namespace std;

void gener_paran(char *output,int n,int index,int open,int close){

// Base Case
    if(index == n * 2){
        // cout<<output<<endl;
        for(int i = 0;i<index;i++){
            cout<<output[i];
        }
        cout<<endl;
        return;
    }
    if(open > close){
        output[index] = ')';
        gener_paran(output,n,index+1,open,close+1);
    }
    if(open < n){
        output[index] = '(';
        gener_paran(output,n,index+1,open + 1,close);
    }
    return;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    char output[10000];
    gener_paran(output,n,0,0,0);
    return 0;
}
