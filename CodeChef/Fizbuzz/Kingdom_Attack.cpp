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

#define ff first
#define ss second

#define int long long
#define mod 1000000007ll
#define endl "\n"
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

pair<int, int> dfs(int v, v(int) Adj[], v(bool) & visited)
{
    visited[v] = true;
    pair<int, int> ans;
    ans.ff = 1;
    ans.ss = Adj[v].size();

    for (int nb : Adj[v])
    {
        if (!visited[nb])
        {
            auto cur = dfs(nb, Adj, visited);
            ans.ff += cur.ff;
            ans.ss += cur.ss;
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    v(int) Adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        cin >> u >> v;

        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    v(bool) visited(n + 1);
    int ans = 0;
    if (2 * m != n * (n - 1))
    {
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                auto cur = dfs(i, Adj, visited);
                if (cur.ff * (cur.ff - 1) == cur.ss)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}
int32_t main()
{
    FastIO;

    w(T)
    {
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //