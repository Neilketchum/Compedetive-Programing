#include<bits/stdc++.h>
using namespace std;
bool canPlace(int mat[25][25],int i,int j,int n,int number){
    // Checking for row and collumn
    for(int a = 0;a<n;a++){
        if(mat[a][j]==number || mat[i][a] == number){
            return false;
        }
    }
    int rn =sqrt(n);
    int sx = (i/rn)*rn;
    int sy = (j/rn) * rn;
    for(int a = sx;a<sx+rn;a++){
        for(int b = sy;b<sy+rn;b++){
            if(mat[a][b] == number){
                return false;
            }
        }
    }
    return true;
}



bool solveSudoku(int mat[25][25],int i,int j ,int n){
    // Base Case
    if(i == n){
        cout<<"*******Soln***********"<<endl;
        for(int a = 0;a< n;a++){
            for(int b = 0;b<n;b++){
                cout<<mat[a][b]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    if( j == n){
        return solveSudoku(mat,i+1,0,n);
    }
    if(mat[i][j]!=0){
        return solveSudoku(mat,i,j+1,n);
    }
    for(int number = 1;number<=n;number++){
        if(canPlace(mat,i,j,n,number)){
            mat[i][j] = number;
            bool CouldSolve  = solveSudoku(mat,i,j+1,n);
            if(CouldSolve){
                return true;
            }            
        }
    }
    mat[i][j] = 0;
    return false;
}
int main() {
    int n;
    cin>>n;
    int sudoku[25][25]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>sudoku[i][j];
        }
    }
     solveSudoku(sudoku,0,0,n);  
}