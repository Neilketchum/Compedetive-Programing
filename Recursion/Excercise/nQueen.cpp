#include<bits/stdc++.h>
using namespace std;
int flag = 0;
bool isSafe(int board[15][15],int i,int j,int n){
    //Checking for Col 
    for(int row = 0;row < i;row++){
        if(board[row][j] == 1){
            return false;
        }
    }
    // Checking for Left Diagonal
    int x = i;
    int y = j;
    while(x>=0 && y>= 0){
        if(board[x][y] == 1 ){
            return false;
        }
        x--;
        y--;
    }
    // CHecking for right diagonal
    x = i;
    y = j;
    while(x>=0 && y< n){
        if(board[x][y] == 1 ){
            return false;
        }
        x--;
        y++;
    }
    return true;
}
bool solveNqueen(int board[15][15],int i,int n){
    if(i == n){
        // for(int row =0 ;row<n;row++){
        //     for(int col = 0;col<n;col++){
        //         cout<<board[row][col]<<' ';
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        flag++;
        return false;
    }
    for(int j = 0;j<n;j++){
        if(isSafe(board,i,j,n)){
            board[i][j] = 1;
            bool nextQueen = solveNqueen(board,i+1,n);
            if(nextQueen){
                return true;
            }
            board[i][j] = 0; //Backtrack
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    int board[15][15] = {0};
    int n;
    cin>>n;
    solveNqueen(board,0,n);
    cout<<flag<<endl;
    return 0;
}
