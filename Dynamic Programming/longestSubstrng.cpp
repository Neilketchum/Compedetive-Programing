 #include<bits/stdc++.h>
 using namespace std;
 int longestSub(string s,string t,int s_len,int t_len,int i,int j){
     if(s[i] == '\0' || t[j] == '\0' ){
         return 0;
     }
     if(s[i] == t[j]){
        //  cout<<s[i]<<endl;
         return longestSub(s,t,s_len,t_len,i+1,j+1) +1;
     }
     else{
         return max(longestSub(s,t,s_len,t_len,i,j+1),longestSub(s,t,s_len,t_len,i+1,j));
     }
 }
 int longestSubDP(int dp[20][20],string s,string t,int s_len,int t_len,int i,int j){
     if(s[i] == '\0' || t[j] == '\0' ){
         return 0;
     }
     if(dp[i][j]!=0)return dp[i][j];
     if(s[i] == t[j]){
        //  cout<<s[i]<<endl;
         return dp[i][j] = longestSubDP(dp,s,t,s_len,t_len,i+1,j+1) +1;
     }
     else{
         return dp[i][j] = max(longestSubDP(dp,s,t,s_len,t_len,i,j+1),longestSubDP(dp,s,t,s_len,t_len,i+1,j));
     }
 }
 int main(int argc, char const *argv[])
 {
    string s = "longest";
    string t = "stone";
    int dp[20][20] = {0};
    int s_len = s.size();
    int t_len = t.size();
    // cout<<longestSub(s,t,s_len,t_len,0,0)<<endl;    
    cout<<longestSubDP(dp,s,t,s_len,t_len,0,0)<<endl;    
    for(int i = 0;i<=s_len;i++){
        for(int j = 0;j<=t_len;j++){
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }
    // cout<<dp[0][2]<<endl;
    // cout<<dp[2][1]<<endl;
    int index;
    int i = 0,j = 0;
    while(true){
        // cout<<"hello"<<endl;
        if(dp[i][j]==0)break;
        if(dp[i][j] == dp[i][j+1]){
            j = j+1;
        }else{
                // cout<<i<<"\t"<<j<<endl;
                cout<<t[j]<<"\t";
                i = i+1;
                j = j+1;         
            }
    }
     return 0;
 }
 