// if you go to date with crush, you cannot participate in the coding contest and you can’t watch the movie. Also if you play DotA, you can’t study for the exam. If you study for the exam you can’t sleep peacefully. The maximum number of activities that you can do for this schedule is 3. 

// Either you can

// watch movie, play DotA and sleep peacefully (or)
// date with crush, play DotA and sleep peacefully
// Input Specifications
// The first line consists of an integer T, the number of test cases. For each test case the first line consists of an integer N, the number of activities. Then the next N lines contains two integers m and n, the start and end time of each activity.

// Output Specifications
// For each test case find the maximum number of activities that you can do.
#include<bits/stdc++.h>
using namespace std;
int partition(int *start,int *end,int s,int e){
   int i = s-1;
   int j = s;
   for(;j<=e-1;){
       if(end[j] <= end[e]){
           i++;
           swap(end[i],end[j]);
           swap(start[i],start[j]);
       }
       j++;
   } 
   swap(end[i+1],end[e]);
   swap(start[i+1],start[e]);
   return i+1;
}
void QuickSort(int *start,int *end,int l,int h){
    if(l>=h){
        return;
    }
    int j = partition(start,end,l,h);
    QuickSort(start,end,l,j-1);
    QuickSort(start,end,j+1,h);
}
int main(int argc, char const *argv[])
{
    int t,n;
    cin>>t;
    vector<pair<int,int>>v;
    while(t>0){
        int n;
        cin>>n;
        int start[n];
        int end[n];
        for(int i = 0;i<n;i++){
            int s,e;
            cin>>s>>e;
            start[i] = s;
            end[i] = e;
        }
        QuickSort(start,end,0,n-1);
        int activ = 1;
        int i  = 0;
        int j = i+1;
        while(i<n){
            while(j<n){
                if(end[i] <= start[j]){
                    activ++;
                    i = j;
                    break;
                }
                j++;
            }
            i++;
            j = i+1;
        }
    }
    return 0;
}
