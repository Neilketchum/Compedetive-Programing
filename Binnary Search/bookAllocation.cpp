// Given number of pages in n different books and m students. The books are arranged in ascending order 
// of number of pages. Every student is assigned to read some consecutive books. The task is to 
// assign books in such a way that the maximum number of pages assigned to a student is minimum.
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
bool bookRakhPaye(int *arr,int n,int m,int min_page){
    int studCount  =1;
    int curr_pages = 0;
    for(int i = 0 ;i<n;i++){
        if((curr_pages + arr[i]) > min_page ){
            studCount++;
            curr_pages = arr[i];
            if(studCount > m){
                return false;
            }
        }else{
            curr_pages += arr[i];
        }
    }
    return true;
}
int findPages(int *arr,int n,int m){
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum+= arr[i];
    }
    int s = 0;
    int e = sum;
    int ans = INT_MAX;
    while(s<=e){
        int mid  = s  + (e - s)/2;
        if(bookRakhPaye(arr,n,m,mid)){
            
            ans = min(ans,mid);
            e = mid - 1;
        }else{
            s = mid+1;
        }
    }
    return ans;
}
int main() 
{ 
    //Number of pages in books 
    int arr[] = {12, 34, 67, 90}; 
    int n = sizeof arr / sizeof arr[0]; 
    int m = 2; //No. of students 
  
    cout << "Minimum number of pages = "
         << findPages(arr, n, m) << endl; 
    return 0; 
}