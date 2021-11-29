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

int dfs(int current, vector<int> *Adj, int parent, int cons, vector<int> &isCat, int lm)
{

    bool isLeaf = true;

    if (isCat[current])
        cons++;
    else
        cons = 0;

    if (cons > lm)
        return 0;

    int ans = 0;

    for (int child : Adj[current])
    {
        if (child == parent)
            continue;
        if (child != parent)
        {
            isLeaf = false;
            ans += dfs(child, Adj, current, cons, isCat, lm);
        }
    }

    if (isLeaf)
        return 1;
    else
        return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> isCat(n + 1, false);

    for (int i = 1; i <= n; i++)
        cin >> isCat[i];

    vector<int> *Adj = new vector<int>[n + 1];
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    int ans = dfs(1, Adj, -1, 0, isCat, m);
    cout << ans << endl;
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