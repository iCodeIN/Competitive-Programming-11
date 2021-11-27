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

#define pair <int, int> pii
#define ff first
#define ss second

#define int long long
#define mod 1000000007ll
#define endl "\n"
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
void dfs(int v, v(int) Adj[], v(bool) & visited, v(int) & l, v(bool) & isL, int lvl = 0)
{
    visited[v] = true;
    l[v] = lvl;
    int c = 0;

    for (int x : Adj[v])
        if (!visited[x])
            dfs(x, Adj, visited, l, isL, lvl + 1), c++;
    isL[v] = c == 0;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    v(int) friends(k);
    for (int i = 0; i < k; i++)
        cin >> friends[i];
    v(int) Adj[n + 1];

    for (int i = 1; i < n; i++)
    {
        int u;
        int v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    // cout << "all";
    // return;
    v(bool) visited(n + 1, false);
    v(int) levels(n + 1, 0);
    v(bool) isLeaf(n + 1, false);
    dfs(1, Adj, visited, levels, isLeaf);

    v(int) dist(n + 1, 0);
    for (int i = 1; i <= n; i++)
        visited[i] = false;

    queue<int> q;
    for (int i = 0; i < k; i++)
        q.push(friends[i]), visited[friends[i]] = 1;

    while (q.size() > 0)
    {
        auto f = q.front();
        q.pop();
        for (int nb : Adj[f])
        {
            if (!visited[nb])
            {
                dist[nb] = dist[f] + 1;
                visited[nb] = true;
                q.push(nb);
            }
        }
    }
    bool ans = false;
    for (int i = 1; i <= n; i++)
    {
        // cout << isLeaf[i] << " " << levels[i] << " " << dist[i] << endl;
        if (isLeaf[i] and levels[i] < dist[i])
            ans = true;
    }
    if (ans)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
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