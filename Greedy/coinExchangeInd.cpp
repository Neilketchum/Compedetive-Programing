// Given a value V, if we want to make a change for V Rs, and we have an 
// infinite supply of each of the denominations in Indian currency, i.e., we
//  have an infinite supply of { 1, 2, 5, 10, 20, 50, 100,200, 500, 2000} valued 
// coins/notes, what is the minimum number of coins and/or notes needed to make the change?
// https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/
#include<bits/stdc++.h>
using namespace std;
int deno[] = { 1, 2, 5, 10, 20, 50, 100, 200,500, 2000 }; 
int lowerBound(int s,int e,int key){
    int min = -1;
    int ans = INT_MIN;
    while(s<=e){
        int mid = (s+e)/2;

        if(deno[mid] > key ){
            e = mid -1;
        }
        if(deno[mid] < key){
            s = mid + 1;
            ans = max(ans,mid); 
        }
        if(deno[mid] == key){
            return mid;
        }
    }
    return ans;
}
void getDeno(int n){
    int m = sizeof(deno)/sizeof(deno[0]);
    while(n>0){
        cout<<deno[lowerBound(0,m-1,n)]<<endl;
        n = n -  deno[lowerBound(0,m-1,n)];
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    getDeno(n);
    return 0;
}
