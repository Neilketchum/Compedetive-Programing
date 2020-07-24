#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Complete the birthdayCakeCandles function below.
int partition(vector<int>&ar,int s,int e){
    int i = s-1;
    int j = s;
    for(;j<=e-1;){
        if(ar[s] <= ar[e]){
            i++;
            swap(ar[i],ar[j]);
        }
        j++;
    }
    swap(ar[i+1],ar[e]);
    return i+1;
}
void QuickSort(vector<int>&ar,int l,int h){
    if(l>=h){
        // sort(ar.begin(),ar.end());
        return;
    }
    int p = partition(ar,l,h);
    QuickSort(ar,l,p-1);
    QuickSort(ar,p+1,h);
}
int main(int argc, char const *argv[])
{
    vector<int>v  = {5,2,1,3,4,7,0,12};
    QuickSort(v,0,v.size()-1);
    for(auto itr :v){
        cout<<itr<<endl;
    }
    return 0;
}
