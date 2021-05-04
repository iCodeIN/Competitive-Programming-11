

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

bool isSafe(int x, int y, int m, int n)
{
    return x >= 0 and y >= 0 and x < m and y < n;
}

void dfs(int x, int y, v(string) & A, v(v(bool)) & visited)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {

        int X = x + dx[i];
        int Y = y + dy[i];
        if (isSafe(X, Y, (int)A.size(), (int)A[0].size()) and A[X][Y] == '.' and !visited[X][Y])
            dfs(X, Y, A, visited);
    }
}

void solve()
{
    int m, n;
    cin >> m >> n;

    v(string) A(m);

    for (int i = 0; i < m; i++)
        cin >> A[i];

    v(v(bool)) visited(m, v(bool)(n, false));

    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] and A[i][j] == '.')
                ans++, dfs(i, j, A, visited);
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //