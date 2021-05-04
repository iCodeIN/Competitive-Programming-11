

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

int dfs(int x, v(v(int)) & adj, v(bool) & visited)
{

    int ans = 1;
    visited[x] = true;
    for (int i = 0; i < adj[x].size(); i++)
    {
        if (!visited[adj[x][i]])
            ans += dfs(adj[x][i], adj, visited);
    }
    return ans;
}

void solve()
{
    int n, e;
    cin >> n >> e;

    v(v(int)) adj(n + 1);

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    int connected_components = 0;
    int captains = 1;

    v(bool) visited(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            connected_components++;
            int nodes = dfs(i, adj, visited);
            captains = (nodes * captains) % mod;
        }
    }

    cout << connected_components << " " << captains << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //