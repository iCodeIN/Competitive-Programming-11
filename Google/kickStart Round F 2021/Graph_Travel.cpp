// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
#include <set>
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

struct node
{
    int l;
    int r;
    int M;
};

set<vector<int>> s;
node A[20];

bool good(v(int) & P, int pos, int k, v(int) Adj[], v(bool) & visited, int curPoints)
{
    if (curPoints == k)
    {
        vector<int> temp(pos);
        for (int i = 0; i < pos; i++)
            temp[i] = P[i];

        s.insert(temp);

        return true;
    }

    if (curPoints > k)
        return false;

    if (pos == P.size())
        return false;

    if (pos == 0)
    {
        visited[P[pos]] = true;
        return good(P, pos + 1, k, Adj, visited, curPoints + A[P[pos]].M);
    }

    // can current be visited

    for (int v : Adj[P[pos]])
    {
        if (visited[v] and A[P[pos]].l <= curPoints and curPoints <= A[P[pos]].r)
        {
            visited[P[pos]] = true;
            return good(P, pos + 1, k, Adj, visited, curPoints + A[P[pos]].M);
        }
    }
    return false;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        auto &d = A[i];
        cin >> d.l >> d.r >> d.M;
    }

    v(int) Adj[n];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    v(int) p(n);

    for (int i = 0; i < n; i++)
        p[i] = i;
    int ans = 0;

    do
    {
        v(bool) visited(n, false);
        if (good(p, 0, k, Adj, visited, 0))
        {
            ans++;
        }

    } while (next_permutation(all(p)));

    ans = s.size();

    cout << ans << endl;

    s.clear();
}

int32_t main()
{
    FastIO;
    int test = 1;
    w(T)
    {
        cout << "Case #" << test++ << ": ";
        solve();
    }
    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //