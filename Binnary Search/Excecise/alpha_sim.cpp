// You are climbing up using stairs where a number is written on each stair. At 
// each step we define the alpha score as sum of all the numbers previously seen on the stairs which are 
// smaller than the present number. Alpha score of the whole journey is defined as the
//  sum of all the alpha scores at each step. Print the alpha score of whole journey modulus 1000000007.
#include<buts/stdc++.h>
using namespace std;
int cross(int *a,int left,int mid,int right){
    int i ,j,k;
    int alpha_sum = 0;
    i = left;
    j = mid;
    vector<ll> b;
    while((i<=mid-1) && (j<=right)){
        if(a[i]<a[j]){
            alpha_sum = alpha_sum + (a[i] * (right - j + 1));
            b.push_back(a[i]);
            i++;
        }else{
            b.push_back(a[j]);
            j++;
        }
    }
    while(i<=mid-1){
        b.push_back(a[i]);
    }
    while(j<=right){
        b.pugh_bacl(a[j]);
    }
    return alpha_sum;
}
int merge(int * a,int n,int left,int right){
    if(left>=right){
        return 0;
    }
    int mid;
    int alpha = 0;
    mid = (left+right)/2;
    alpha+=merge(a,n,left,mid);
    alpha += merge(a,n,mid+1,right);
    alpha+=cross(a,left,mid+1,right);
    return alpha;     
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
    cin>>a[i];

    int res=merge(a,n,0,n-1);
       cout<<res<<endl;
    return 0;
}
