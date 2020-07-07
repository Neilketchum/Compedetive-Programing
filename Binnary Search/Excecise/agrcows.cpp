//  Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are 
//  located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

//  His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other
//  once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to
// the stalls, such that the  minimum distance between any two of them is as large
//  as possible. What is the largest minimum distance?
#include<bits/stdc++.h>
using namespace std;
bool canPlace(vector<int>stall_index,int stalls,int cows,int sep){
    int cowPlaced = 1;
    int last_cow_pos = stall_index[0];
    for(int i =1;i<stalls;i++){
        if((stall_index[i] - last_cow_pos) >= sep ){
            cowPlaced++;
            last_cow_pos = stall_index[i];
            if(cowPlaced == cows){
                return true;
            }
        }
    }
    return false;
}
int min_distance(vector<int>stall_index,int stalls,int cows){
    int s = 0;
    int  e = stall_index[stalls-1] ;

    int min_dis = 0;
    while(s<=e){
        int mid = (s+e)/2;
        if(canPlace(stall_index,stalls,cows,mid)){
            // cout<<min_dis<<endl;
            min_dis = mid;
            s = mid+1;
        }
        else{
            e = mid -1;
        }
    }
    return min_dis;
}
int main(int argc, char const *argv[])
{
    int t;
    t =1;
    while(t > 0){
        int stalls ,cows;
        cin>>stalls>>cows;
        vector<int>stall_index(stalls);
        for(int i = 0;i<stalls;i++){
            cin>>stall_index[i];
        }
        sort(stall_index.begin(),stall_index.end());
        cout<<min_distance(stall_index,stalls,cows);
        t--;
    }
    return 0;
}
