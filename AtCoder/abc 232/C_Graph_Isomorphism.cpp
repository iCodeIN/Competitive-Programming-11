// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
/* author : pasricha_dhruv */
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#include <bits/stdc++.h>
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
using namespace std;
using LL = long long int;
using LD = long double;
using vi = vector<LL>;
using pii = pair<LL, LL>;
const LL mod = 1e9 + 7;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#define all(x) x.begin(), x.end()
#define double LD
#define endl "\n"
#define ff first
#define int LL
#define ss second
#define v vector
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

bool f(v<int> &A, v<set<int>> &Adj1, v<pii> &edges)
{
    int n = A.size();
    v<set<int>> Adj(n);

    for (auto &edge : edges)
    {
        int u = A[edge.ff];
        int v = A[edge.ss];
        Adj[u].insert(v);
        Adj[v].insert(u);
    }

    return Adj == Adj1;
}
void solve()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    v<set<int>> Adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u].insert(v);
        Adj[v].insert(u);
    }

    v<pii> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i].ff = u;
        edges[i].ss = v;
    }

    v<int> perm(n + 1);
    for (int i = 1; i <= n; i++)
        perm[i] = i;

    bool ok = false;
    do
    {
        if (perm[1] == 0)
            break;
        ok = f(perm, Adj, edges);
        if (ok)
            break;

    } while (next_permutation(all(perm)));

    if (ok)
        cout << "Yes";
    else
        cout << "No";
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //