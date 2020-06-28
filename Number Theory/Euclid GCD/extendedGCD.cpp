// GCD(a,b) * LCM(a,b) = a*b;
#include<bits/stdc++.h> 
using namespace std;
int x,y,GCD;
void extendedEuclid(int a,int b){
    // Base Case
    if(b == 0){
        GCD = a;
        x = 1;
        y = 0;
        return ;
    }
    // Recursive Case
    extendedEuclid(b,a%b);
    int cX = y;
    int cY = x - (a/b)*y;
    x = cX;
    y = cY;
} 
int main(int argc, char const *argv[])
{
    // 18x + 30 y = 6 ;
    extendedEuclid(18,30);
    cout<<x<<" "<<y<<endl;
    return 0;
}
