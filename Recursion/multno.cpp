// Multiply without *
#include<bits/stdc++.h>
using namespace std;
int mult(int a,int b){
    if(b == 0){
        return 0;
    }
    return a + mult(a,b-1);

}
int main(int argc, char const *argv[])
{
    cout<<mult(7,6)<<endl;
    return 0;
}
