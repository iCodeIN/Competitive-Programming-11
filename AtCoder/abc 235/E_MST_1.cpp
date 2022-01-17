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

struct DSU
{

    vector<int> Parent;
    vector<int> Size;

    DSU(int n)
    {
        Parent.resize(n);
        Size.assign(n, 1);
        for (int i = 0; i < n; i++)
            Parent[i] = i;
    }

    int get(int x)
    {

        if (Parent[x] == x)
        {
            return x;
        }
        return Parent[x] = get(Parent[x]);
    }

    void Union(int a, int b)
    {

        a = get(a);
        b = get(b);

        if (a == b)
            return;

        if (Size[a] < Size[b])
        {
            swap(a, b);
        }

        // Now a is bigger
        Size[a] += Size[b];
        Parent[b] = a;
    }
};

struct edge
{
    bool query = false;
    int w;
    int u;
    int v;
    int idx = -1;
};

bool comp(edge a, edge b)
{
    return a.w < b.w;
}

void solve()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    int q;
    cin >> q;

    v<edge> A(m + q);
    int i = 0;
    for (int i = 1; i <= m; i++)
    {
        edge cur;
        cin >> cur.u >> cur.v >> cur.w;
        A[i - 1] = cur;
    }

    for (int i = 1; i <= q; i++)
    {
        edge cur;
        cin >> cur.u >> cur.v >> cur.w;
        cur.idx = i - 1;
        cur.query = true;
        A[m + i - 1] = cur;
    }
    sort(all(A), comp);
    DSU dsu(n + 1);
    v<int> Ans(q, 0);
    for (int i = 0; i < m + q; i++)
    {
        int u = dsu.get(A[i].u);
        int v = dsu.get(A[i].v);

        // cout << A[i].u << " " << A[i].v << " " << A[i].w << endl;
        if (u != v)
        {
            if (A[i].query)
            {
                // cout << A[i].idx << endl;
                Ans[A[i].idx] = 1;
            }
            else
                dsu.Union(u, v);
        }
    }
    for (int x : Ans)
    {
        if (x == 1)
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
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