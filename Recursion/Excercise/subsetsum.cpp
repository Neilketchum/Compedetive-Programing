#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int sum(int *arr,int size){
    int sum = 0;
    for(int i = 0;i<size;i++){
        sum+=arr[i];
    }
    return sum;
}
int subset(int *input,int *output,int i,int j,int n,int cnt){
    if(i == n){
        
        // cout<<endl;
        if(sum(output,j) == 0){
            cnt++;
        }
        return cnt;
    }
    output[j] = input[i];
    cnt = subset(input,output,i+1,j+1,n,cnt);
    cnt = subset(input,output,i+1,j,n,cnt);
    return cnt;
}
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int input[n] ;
        for(int i =0;i<n;i++){
            cin>>input[i];
        }
        int output[n+1] = {0};
        int count = subset(input,output,0,0,n,-1);
  
        if(count > 0){
          cout<<"Yes"<<endl;  
        }else{
            cout<<"No"<<endl;
        }
        t--;
    }
    return 0;
}
