
// Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:

// Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

// Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”
// Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”
// Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”
// Alice: “How many different decodings?”
// Bob: “Jillions!”

// For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.
#include<bits/stdc++.h>
using namespace std;
char alpha[26] = {'#','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','y','z'};
int totalAlpha = 26;
void generateAcode(char *in,char *out,int i,int j){
    if(in[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }
    int currdigit = in[i] - '0';
    if(in[i+1]!='\0'){
        int nextdigit = in[i+1] - '0';
        if((currdigit*10)+nextdigit < 26){
            // cout<<alpha[(currdigit*10)+nextdigit]<<endl;
            out[j] = alpha[(currdigit*10)+nextdigit];
            generateAcode(in,out,i+2,j+1);
        }
    }
    
    
    out[j] =alpha[currdigit];
    generateAcode(in,out,i+1,j+1);
    return;
    
}
int main(int argc, char const *argv[])
{
    char in[1000];
    cin>>in;
    char out[100000];
    int i= 0,j= 0;
    generateAcode(in,out,i,j);    
    return 0;
}
