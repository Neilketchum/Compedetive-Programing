#include<bits/stdc++.h>
using namespace std;
bool ratinMaze(char maze[10][10],int sol[][10],int i,int j,int m,int n){
    // Base Cases
    if(i == m && j == n){
        sol[i][j] = 1;
        for(int a = 0;a<=m;a++){
            for(int b = 0;b<=n;b++){
                cout<<sol[a][b]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    if(i>m || j>n){
        return  false; //Stay inside the maze
    }
    if(maze[i][j] == 'X'){
        return false;
    }
    // Assuming path exist from the curent cube
    sol[i][j] = 1;

    bool right = ratinMaze(maze,sol,i,j+1,m,n);
    bool down = ratinMaze(maze,sol,i+1,j,m,n);

    // Backtracking
    sol[i][j] = 0;

    if(right|| down){
        return true;
    }
    return false;
}
int main(int argc, char const *argv[])
{
    char maze[10][10] = { "0000",
                            "00X0",
                            "000X",
                            "0x00"};

    int soln[10][10] = {0};
    int m = 4,n = 4;
    bool ans= ratinMaze(maze,soln,0,0,m-1,n-1);
    return 0;
}
