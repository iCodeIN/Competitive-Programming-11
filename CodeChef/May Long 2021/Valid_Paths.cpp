

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
static int dp[200010];

int solve(int v, v(v(int)) & adj, v(bool) & visited, v(int) & options)
{
    visited[v] = true;

    int smallAns = 0;

    for (int &x : adj[v])
        if (!visited[x])
            smallAns = (smallAns + solve(x, adj, visited, options)) % mod;

    int ans = (2 * smallAns + 1) % mod;

    return options[v] = ans;
}

int solve2(int v, v(v(int)) & adj, v(bool) & visited, v(int) & options)
{
    visited[v] = true;

    int ans = 0;

    int sqsum = 0;
    int sum = 0;
    int children = 0;

    for (int &x : adj[v])
    {
        if (!visited[x])
        {
            int n = options[x];
            int n_ = (n * n) % mod;
            sqsum = (sqsum + n_) % mod;
            sum = (sum + n) % mod;
            children++;
        }
    }
    if (children > 1)
    {
        sum = (sum * sum) % mod;
        ans = (sum - sqsum) % mod;
        ans = (ans + mod) % mod;
    }
    int ans2 = 0;
    for (int &x : adj[v])
        if (!visited[x])
            ans2 = (ans2 + solve2(x, adj, visited, options)) % mod;
    ans = (ans + ans2) % mod;

    return ans;
}

void solve()
{
    int n;
    cin >> n;
    v(v(int)) adj(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    v(bool) visited(n + 1, false);
    v(int) options(n + 1, 0);
    auto ans1 = solve(1, adj, visited, options);

    visited.clear();
    visited.assign(n + 1, false);

    auto ans2 = solve2(1, adj, visited, options);
    int ans = (ans1 + ans2) % mod;
    cout << ans << endl;
}

int32_t main()
{
    FastIO;
    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
