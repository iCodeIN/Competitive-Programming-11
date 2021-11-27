// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
/* author : pasricha_dhruv */
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#include <algorithm>
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
    int u;
    int v;
};

void solve()
{
    int n, m;
    cin >> n >> m;

    v(edge) A(m);
    DSU dsu(n + 10);

    for (int i = 0; i < m; i++)
    {
        cin >> A[i].u >> A[i].v;
        if (A[i].u > A[i].v)
            swap(A[i].u, A[i].v);
    }

    sort(all(A), [](edge a, edge b)
         {
             if (a.u != b.u)
                 return a.u > b.u;
             return a.v > b.v;
         });
    int i = 0;
    v(int) Ans(n + 1, 0);
    Ans[n] = 0;
    for (int j = n - 1; j >= 0; j--)
    {

        // include j + 1 vertex
        int ans = Ans[j + 1] + 1;
        while (i < m and A[i].u == j + 1)
        {
            int p1 = dsu.get(j + 1);
            int p2 = dsu.get(A[i].v);

            if (p1 != p2)
                dsu.Union(j + 1, A[i].v), ans--;
            i++;
        }
        Ans[j] = ans;
    }
    for (int i = 1; i <= n; i++)
        cout << Ans[i] << endl;
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