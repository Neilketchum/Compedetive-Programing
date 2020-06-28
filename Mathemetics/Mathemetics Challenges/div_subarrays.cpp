#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;


int main() {
	ll int n;
	
	int t;
	cin>>t;
	while(t>0)
	{
	    cin>>n;
	
	    int a[n];
        int sum=0;
        long long c[n];
        for(int i=0;i<n;i++)
            c[i]=0;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        if(a[i]<0)
	            a[i]=n-((-a[i])%n);
	        else
	            a[i]=a[i]%n;
	           
            sum=(sum+a[i])%n;
            c[sum]++;
	    
	    }
	
        ll int  val=0;
        c[0]++;
        for(ll int i=0;i<n;i++)
            if(c[i]>=2)
                val=val +(c[i]*(c[i]-1)/2);
      

        cout<<val<<endl;
    
        t--;
   
	}

}