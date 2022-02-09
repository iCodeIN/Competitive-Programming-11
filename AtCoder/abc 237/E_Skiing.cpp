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
int cost(int x, int y)
{

    if (x >= y)
        return x - y;

    return 2 * (x - y);
}

void solve()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    v<int> A(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> A[i];

    v<int> Adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    v<int> H(n + 1, INT_MIN);
    priority_queue<pii> pq;
    v<bool> visited(n + 1, false);

    int ans = 0;

    pq.push({0, 1});

    while (pq.size())
    {
        auto f = pq.top();
        pq.pop();

        if (visited[f.ss] and f.ss == 1)
        {
            continue;
        }

        visited[f.ss] = true;
        ans = max(ans, f.ff);

        // cout << "{" << f.ss << "," << f.ff << " } : ";
        for (int &nb : Adj[f.ss])
        {
            // if (visited[nb])
            //     continue;
            int cur = cost(A[f.ss], A[nb]) + f.ff;
            // cout << nb << " " << cur << endl;
            if (cur >= H[nb])
            {
                // cout << nb << ", ";
                pq.push({cur, nb});
                H[nb] = cur;
                ans = max(ans, cur);
            }
        }
    }
    cout << ans << endl;
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