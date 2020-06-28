// knight is a piece used in the game of chess. The chessboard itself is square array of cells. Each time a knight moves, its resulting position is two rows and one column, or two columns and one row away from its starting position. Thus a knight starting on row r, column c – which we’ll denote as (r,c) – can move to any of the squares (r-2,c-1), (r-2,c+1), (r-1,c-2), (r-1,c+2), (r+1,c-2), (r+1,c+2), (r+2,c-1), or (r+2,c+1). Of course, the knight may not move to any square that is not on the board.

// Suppose the chessboard is not square, but instead has rows with variable numbers of columns, and with each row offset zero or more columns to the right of the row above it. The figure to the left illustrates one possible configuration. How many of the squares in such a modified chessboard can a knight, starting in the upper left square (marked with an asterisk), not reach in any number of moves without resting in any square more than once? Minimize this number.

#include<bits/stdc++.h>
using namespace std;
int n,cols,empty,board[10][10],sum,hi;
void check_boxes(int i,int j,int count){
    if(i<0 || i>=10 || j<0 || j>=10 || board[i][j] == 0 ){
        return ;
    }
    int ans = 0;
    board[i][j] = 0; //Uncheck_boxess board[i][j]
    hi = max(hi,count+1);
    check_boxes(i-1,j-2,count+1);
    check_boxes(i-2,j-1,count+1);
    check_boxes(i+1,j-2,count+1);
    check_boxes(i+2,j-1,count+1);
    check_boxes(i-1,j+2,count+1);
    check_boxes(i-2,j+1,count+1);
    check_boxes(i+1,j+2,count+1);
    check_boxes(i+2,j+1,count+1);
    board[i][j] = 1; //BackTrack
}
int main(int argc, char const *argv[])
{
    cin>>n;
    sum  = 0;
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin>>board[i][j];
            if(board[i][j]){
                sum++; //Sum stores the vallid cells
            }
        }
    }
    hi = 0;
    check_boxes(0,0,0);
    cout<<sum-hi<<endl;
    return 0;
}
