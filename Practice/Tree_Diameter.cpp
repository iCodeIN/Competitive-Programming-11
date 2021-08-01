

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

#define deb(x) cout << #x << " : " << x << endl;

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

int dfs(int v, v(v(int)) & Adj, int &finalAns, v(bool) & visited)
{
    visited[v] = true;
    int h1 = 0, h2 = 0;
    for (int x : Adj[v])
    {
        if (!visited[x])
        {
            int h = dfs(x, Adj, finalAns, visited);

            if (h > h1)
            {
                h2 = h1;
                h1 = h;
            }
            else if (h > h2)
            {
                h2 = h;
            }
        }
    }
    finalAns = max(h1 + h2 + 1, finalAns);

    return h1 + 1;
}

void solve()
{
    int n;
    cin >> n;

    v(v(int)) Adj(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    int ans = 0;

    v(bool) visited(n + 1, false);
    dfs(1, Adj, ans, visited);

    cout << ans - 1 << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //