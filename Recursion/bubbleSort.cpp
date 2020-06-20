#include<bits/stdc++.h>
using namespace std;
// void bubbleSort(int *a,int n){
//     // Base Case
//     if(n == 1)
//     {
//         return ;
//     }
//     // Recursive Case
//     // for(int j = 0;j<n-1;j++){
//     //     if(a[j]>a[j+1]){
//     //          swap(a[j],a[j+1])
//     //     }
//     // }
//     bubbleSort(a,n-1);


// }
void recurbubbleSort(int *a,int j,int n){
    if(n == 1){
        return;
    }
    if(j == n-1){
        return recurbubbleSort(a,0,n-1); //Inner loop completed for a whole outer loop
    }
    if(a[j]>a[j+1]){
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
    }
    recurbubbleSort(a,j+1,n); //For next inner loop
}
int main(int argc, char const *argv[])
{
    int a[] = {5,4,3,1,2};
    int n = sizeof(a)/sizeof(int);
  
    recurbubbleSort(a,0,n);
    for(auto x:a){
        cout<<x<<endl;
    }
    
    return 0;
}
