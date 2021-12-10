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

v(int) Ans;

void dfs(int root, int parent, v(int) Adj[], bool oneUp, bool twoUp, v(int) & act, v(int) & exp)
{
    if (twoUp == false)
        act[root] ^= 1;

    bool current = twoUp;

    if (act[root] != exp[root])
        act[root] = exp[root], Ans.push_back(root), current != current;

    for (int child : Adj[root])
        if (child != parent)
            dfs(child, root, Adj, current, oneUp, act, exp);
}

void solve()
{
    int n;
    cin >> n;

    v(int) Adj[n + 1];

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    v(int) actual(n + 1);
    v(int) expected(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> actual[i];
    for (int i = 1; i <= n; i++)
        cin >> expected[i];

    dfs(1, -1, Adj, true, true, actual, expected);

    for (int i = 1; i <= n; i++)
        cout << actual[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << expected[i] << " ";

    cout << endl;

    cout << Ans.size() << endl;
    for (int x : Ans)
        cout << x << endl;
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