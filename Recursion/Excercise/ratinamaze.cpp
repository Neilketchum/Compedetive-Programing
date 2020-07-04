#include <bits/stdc++.h>
using namespace std;
int soln[1000][1000] = {0};
bool ratInMaze(char maze[1000][1000], int soln[1000][1000], int n, int m, int i, int j, int &res)
{
    if (i == n && j == m)
    {
        if (res == 0)
        {
            soln[n - 1][m - 1] = 1;
            for (int a = 0; a < n; a++)
            {
                for (int b = 0; b < m; b++)
                {
                    cout << soln[a][b] << ' ';
                }
                cout << endl;
            }
            res++;
        }

        return true;
    }
    if (i > n || j > m || maze[i][j] == 'X')
    {
        return false;
    }
    soln[i][j] = 1;
    bool right = ratInMaze(maze, soln, n, m, i, j + 1, res);
    bool down = ratInMaze(maze, soln, n, m, i + 1, j, res);
    soln[i][j] = 0;
    if (right || down)
    {
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int m, n;
    char maze[1000][1000];
    // for(int i = 0;)
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
        }
    }
    int res = 0;
    ratInMaze(maze, soln, n, m, 0, 0, res);
    if(res == 0){
        cout<<-1<<endl;
    }
    return 0;
}
