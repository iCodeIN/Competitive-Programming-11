// 2 degree 1
// n - 2 degree 2

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

#define pair <int, int> pii
#define ff first
#define ss second

#define int long long
#define mod 1000000007ll
#define endl "\n"
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
bool dfs(int x, int parent, vector<int> Adj[], vector<bool> &visited)
{
    visited[x] = true;

    int ans = true;

    for (int nb : Adj[x])
        if (visited[nb])
        {
            if (nb == parent)
                continue;
            else
                return false;
        }
        else
        {
            ans &= dfs(nb, x, Adj, visited);
        }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> degree(n + 1);
    vector<int> Adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    int x = -1;
    int mxDegree = 0;
    for (int i = 1; i <= n; i++)
    {
        mxDegree = max(mxDegree, degree[i]);
        if (degree[i] = 1)
            x = i;
    }

    if (mxDegree > 2 or x == -1)
        cout << "No";
    else
    {
        bool ans = true;
        // mxDegree <= 2
        // x != -1

        vector<bool> visited(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                ans &= dfs(i, -1, Adj, visited);
            }
        }

        if (ans)
            cout << "Yes";
        else
            cout << "No";
    }
}
int32_t main()
{
    FastIO;

    // w(T)
    {
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //