#include<bits/stdc++.h>
using namespace std;
bool integer(float k)
    {
        if( k == (int) k) 
            return true;
        return false;
    }
int main(int argc, char const *argv[])
{

    while(true){
        int max_load = 0,load = 0,n;
        cin>>n;
        int arr[n];
        if(n == -1){
            break;
        }
        for(int i = 0;i<n;i++){
            cin>>arr[i];
            load+=arr[i];
        }
        if(load%n!=0){
            cout<<-1<<endl;
            continue;
        }
        int diff = 0;
        load = load/n;
        for(int i = 0;i<n;i++){
            diff += (arr[i] - load);
            max_load = max(max_load,abs(diff));
        }
        cout<<max_load<<endl;
    }
     return 0;
}
