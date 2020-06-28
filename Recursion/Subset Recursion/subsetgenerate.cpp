#include<bits/stdc++.h>
using namespace std;
void gernatesubsequence(char *in,char *out,int i,int j){
    if(in[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }
    out[j] = in[i];
    // Include the current Charecter
    gernatesubsequence(in,out,i+1,j+1);
    // Exclude Current Charecter
    gernatesubsequence(in,out,i+1,j);
}


int main(int argc, char const *argv[])
{
    char input[] = "abc";
    char output[10];
    gernatesubsequence(input,output,0,0);
    return 0;
}
