

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

v(int) dp(3002);

int dfs(const int &root, int cur, v(v(int)) & adj, v(bool) & visited, int lvl = 0)
{
    visited[cur] = true;
    int ans = (root >= cur) ? 0 : dp[lvl - 1];
    for (int i = 0; i < adj[cur].size(); i++)
        if (!visited[adj[cur][i]])
        {
            int temp = dfs(root, adj[cur][i], adj, visited, lvl + 1);
            ans = (ans + temp) % mod;
        }
    return ans;
}

void solve()
{
    int n;
    cin >> n;

    v(v(int)) adj(n + 1);

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = n;

    for (int i = 1; i <= n; i++)
    {
        v(bool) visited(n + 1, false);
        ans = (ans + dfs(i, i, adj, visited)) % mod;
    }

    cout << ans << endl;
}

int32_t main()
{
    FastIO;
    dp[0] = 1;
    for (int i = 1; i <= 3001; i++)
        dp[i] = (dp[i - 1] * 2) % mod;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //