// You are given a matrix with N rows and M columns. Each cell is either dry or has water. We say that two cells are neighbours if they share one of their four sides. A pond is a maximal subset of cells containing water such that any cell is accessible from any other cell by moving only along neighbours. You should add water to exactly one cell in order to maximise the size of the pond.
#include<bits/stdc++.h>
using namespace std;
int countofPond(vector<vector<int>>matrix,int row,int col){
    int count = 0;
    for(int i = 1;i<row;i++){
        for(int j = 1;j<col;j++){
            if(matrix[i][j]){
                // if(i == 0 && j< col){
                //     if(matrix[i+1][j] || matrix[i][j+1] || matrix[i][j-1]){
                //         count++;
                //     }
                // }else if(j == 0 && j<row && j > 0){
                    
                // }
                if(matrix[i+1][j] || matrix[i-1][j] || matrix[i][j+1] || matrix[i][j-1]){
                    count ++;
                }

            }
        }
    }
    return count;
}
int expandPond(vector<vector<int>>matrix,int row,int col){
    int res = -1,temp;
    
    for(int i = 0;i<row;i++){
        for(int j =0;j<col;j++){
            if(matrix[i][j] == 0){
                matrix[i][j] = 1;
                temp = countofPond(matrix,row,col);
                res = max(res,temp);
                matrix[i][j] = 0;//BackTrack
            }
        }
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>matrix(n+2,vector<int>(m+2));
    for(int i =0;i<=n+1;i++){
        for(int j =0;j<=m+1;j++){
            if(i == 0 or j == 0 or i==n+1 or j == m+1){
                matrix[i][j] == -1;
            }
            
        }
    }
    for(int i =1;i<n+1;i++){
        for(int j =1;j<m+1;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<expandPond(matrix,n+1,m+1)<<endl;
    
    return 0;
}
