#include<bits/stdc++.h>
using namespace std;
bool isSorted(int *a,int n){
    if(n == 0 or n == 1){
        return true;
    }
    if(a[0] < a[1] and isSorted(a+1,n-1)){
        return true;
    }
    return false;
}
int main(int argc, char const *argv[])
{
    int arr[] = {1,24,45,154};
    cout<<isSorted(arr,4);
    return 0;
}
