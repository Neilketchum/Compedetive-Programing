// Given a collection of numbers containing duplicates, print all possible permutations for the given collection of numbers in a lexicographic manner. Make sure that no two permutations are same.
// NOTE: Try doing it without using SET or MAP!
#include<bits/stdc++.h>
using namespace std;

void permute(vector<int> input,int i){
    if(i == input.size()){
        for(auto x:input){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    for(int j = i ;j<input.size();j++){
        if(j==i || input[j] != input[i] ){
            swap(input[i],input[j]);
            permute(input,i+1);
            // swap(input[i],input[j]);
        }
        
    }
}
int main(int argc, char const *argv[])
{
  
    int n;
    cin>>n;
    vector<int>input(n);
    for(int i = 0;i<n;i++){
        cin>>input[i];
    }
    sort(input.begin(),input.end());
    permute(input,0);
    return 0;
}