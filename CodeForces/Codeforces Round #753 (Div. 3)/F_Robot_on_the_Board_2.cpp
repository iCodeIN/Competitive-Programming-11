

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
// #include <vector>

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#define w(T)  \
    int T;    \
    cin >> T; \
    while (T--)

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

int n;
int m;

bool valid(int x, int y)
{
    return x >= 0 and x < n and y >= 0 and y < m;
}

int dp[2001][2001];
char A[2001][2001];

int dfs(int x, int y)
{
    if (dp[x][y] == -1)
        return 0;

    dp[x][y] = -1;

    if (A[x][y] == 'R' and valid(x, y + 1))
    {
        return dp[x][y] = 1 + dfs(x, y + 1);
    }
    else if (A[x][y] == 'L' and valid(x, y - 1))
    {
        return dp[x][y] = 1 + dfs(x, y - 1);
    }
    else if (A[x][y] == 'U' and valid(x - 1, y))
    {
        return dp[x][y] = 1 + dfs(x - 1, y);
    }
    else if (A[x][y] == 'D' and valid(x + 1, y))
    {
        return dp[x][y] = 1 + dfs(x + 1, y);
    }

    return dp[x][y] = 1;
}

void solve()
{
    // int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dp[i][j] = INT32_MAX;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (dp[i][j] == INT32_MAX)
            {
                dfs(i, j);
            }
        }

    pair<int, int> ans;
    int M = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (dp[i][j] > M)
                M = dp[i][j], ans.first = i + 1, ans.second = j + 1;

    cout << ans.first << " " << ans.second << " " << M << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //