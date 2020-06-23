#include<bits/stdc++.h>
using namespace std;
void generate(char *out,int n,int indx,int open,int close){

    // Base Case
    if(indx == 2*n){
        cout<<out<<endl;
        return;
    }
    // recursive Case
    if(open<n){
        out[indx] = '(';
        generate(out,n,indx+1,open+1,close);
    }
    if(close<open){
        out[indx] = ')';
        generate(out,n,indx+1,open,close+1);
    }

}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    char output[100000];
    generate(output,n,0,0,0);
    return 0;
}
