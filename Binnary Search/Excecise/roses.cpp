#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{   
    int t;
    cin>>t;
    while(t > 0){
        int n;
        cin>>n;
        int x,y;
        int arr[n];
        for(int i =0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        // cout<<arr[0]<<arr[n-1];
        int target;
        cin>>target;
        int i = 0;
        int j = n-1;
        int diff = INT_MAX;
        while (i < j)
        {
            int sum = arr[i] + arr[j];
            // cout<<arr[i]<<' '<<arr[j]<<' '<<sum<<endl;
            if(sum > target){
                j--;
            }
            else if(sum < target){
                i++;
            }
            if(sum == target){
                // cout<<i<<j<<endl;
                if(diff > abs(arr[i]-arr[j])){
                    cout<<i<<'\t'<<j<<endl;
                    diff = abs(arr[i]-arr[j]);
                    x = i;
                    y = j;
                    i++;      
                }
            }
        }
        cout<<"Deepak should buy roses whose prices are "<<arr[x]<<" and "<<arr[y]<<'.'<<endl;
        t--;
    }
    return 0;
}

