#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dfs(int x, int y, int **mat, vector<vector<int>> &visited)
{

    if (visited[x][y] != -1)
        return visited[x][y];
    int n = visited.size();
    int ans = 1;
    for (int i = 0; i < 4; i++)
    {

        int X = x + dx[i];
        int Y = y + dy[i];
        if (X >= 0 and X < n and Y >= 0 and Y < n and mat[x][y] + 1 == mat[X][Y])
            ans = max(ans, 1 + dfs(X, Y, mat, visited));
    }
    return ans;
}

int LongestPath(int **mat, int n)
{
    vector<vector<int>> Visited(n, vector<int>(n, -1));

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (Visited[i][j] == -1)
            {
                ans = max(ans, dfs(i, j, mat, Visited));
            }
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    int **A = new int *[n];
    for (int i = 0; i < n; i++)
        A[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << LongestPath(A, n);
}
