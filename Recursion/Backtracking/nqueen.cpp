#include <bits/stdc++.h>
using namespace std;
bool isSafe(int board[10][10],int i,int j,int n){
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
bool solveNqueen(int board[][10], int i, int n)
{
    // Base Case
    if (i == n )
    {
        // board[i][j] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return false;
    }
    // traversing collumn for a given row to find a place for the queen
    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, i, j, n))
        {
            // Place the queen and assumeing its right pos
            board[i][j] = 1;
            bool aglaQueenRakhPau = solveNqueen(board, i + 1, n);
            if (aglaQueenRakhPau)
            {
                return true;
            }
            // Asumed Positon of the queen is wrong hence Backtrack
            board[i][j] = 0;
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    int board[10][10] = {0};
    int n;
    cin >> n;
    solveNqueen(board, 0, n );
    return 0;
}
