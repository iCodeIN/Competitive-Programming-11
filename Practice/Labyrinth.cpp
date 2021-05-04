

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>
#include <vector>

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

using namespace std;

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#define w(T)  \
    int T;    \
    cin >> T; \
    while (T--)

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define v(Type) vector<Type>
#define all(x) x.begin(), x.end()

#define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool safe(int x, int y, int m, int n)
{
    return x >= 0 and y >= 0 and x < m and y < n;
}

bool dfs(int x, int y, v(v(bool)) & visited, v(string) & A, v(char) & path)
{

    visited[x][y] = true;

    if (A[x][y] == 'B')
    {
        cout << "YES\n";
        cout << path.size() << endl;
        for (int i = 0; i < path.size(); i++)
            cout << path[i];

        return true;
    }

    for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        int m = A.size();
        int n = A[0].size();

        if (safe(X, Y, m, n) and (A[X][Y] == '.' or A[X][Y] == 'B') and visited[X][Y] == false)
        {
            char ch = 'R';

            if (i == 1)
                ch = 'L';
            else if (i == 2)
                ch = 'D';
            else if (i == 3)
                ch = 'U';

            path.push_back(ch);

            bool found = false;
            found = dfs(X, Y, visited, A, path);

            path.pop_back();

            if (found)
                return true;
        }
    }
    return false;
}

void solve()
{
    int m, n;
    cin >> m >> n;

    v(string) A(m);
    for (int i = 0; i < m; i++)
        cin >> A[i];

    v(char) Path;
    v(v(bool)) visited(m, v(bool)(n, false));
    bool found = false;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] == 'A')
                found = dfs(i, j, visited, A, Path);

    if (!found)
        cout << "NO";
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //