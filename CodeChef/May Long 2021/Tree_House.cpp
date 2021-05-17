

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
// #include <set>
#include <queue>
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

int dfs(int v, v(v(int)) & adj, v(bool) & visited)
{
    visited[v] = true;
    priority_queue<int> pq;
    for (int &x : adj[v])
        if (!visited[x])
            pq.push(dfs(x, adj, visited));

    int m = pq.size();
    int ans = 1;
    for (int i = 1; i <= m; i++)
    {
        ans += (i * pq.top());
        pq.pop();
    }
    return ans;
}

void solve()
{
    int n, x;
    cin >> n >> x;

    v(v(int)) adj(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    v(bool) visited(n + 1, false);

    int ans = dfs(1, adj, visited);

    ans %= mod;
    ans = (ans * x) % mod;
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