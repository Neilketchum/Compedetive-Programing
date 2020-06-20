#include<bits/stdc++.h>
using namespace std;
void partition(int *a,int s,int e){
    int i = ;
    int j = ;



}





void quickSort(int *arr,int s,int e){

    if(s>=e){
        return;
    }
    int p =partition(arr,s,e);
    
    quickSort(arr,s,p-1);

    quickSort(arr,p+1,e);

}



int main(int argc, char const *argv[])
{
    int arr[] = {2,7,8,6,1,5,4};
    int n =sizeof(arr)/sizeof(int);
    quickSort(arr,0,n-1);
    return 0;
}
