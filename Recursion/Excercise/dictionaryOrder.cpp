#include<bits/stdc++.h>
using namespace std;
set<string>st;
void permute(string str,int indx){
    if(indx == str.size()){
        st.insert(str);
        return;
    }
    for(int j = indx;j < str.size();j++){
        swap(str[indx],str[j]);
        permute(str,indx+1);
        swap(str[indx],str[j]);//Backtrack
    }
}
int main(int argc, char const *argv[])
{
    string str;
    cin>>str;
 
    
    
    permute(str,0);
    int flag = 0;
    for(auto x:st){
        if(x ==str )
            flag++;
        if(flag){
            cout<<x<<endl;
        }
    }
    return 0;
}
