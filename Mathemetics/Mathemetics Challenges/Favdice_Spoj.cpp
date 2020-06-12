// Coupon Collector Problem
// BuggyD loves to carry his favorite die around. Perhaps you wonder why it's his
//  favorite? Well, his die is magical and can be transformed into an N-sided unbiased 
//  die with the push of a button. Now BuggyD wants to learn more about his die, so he raises a question:

// What is the expected number of throws of his die while it has N sides so that each number is rolled at least once?


#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{   
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        double sum = 0.00;
        for(double i = 1;i<= n;i++){
            sum += 1/i;
        }
        sum = sum*n;
        cout<<setprecision(2)<<fixed<<sum<<endl;
            t--;
    }

    return 0;
}
