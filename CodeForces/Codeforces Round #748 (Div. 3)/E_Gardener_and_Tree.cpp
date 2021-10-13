

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

#define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

void solve(v(int) & dp, v(int) Adj[])
{

    int n = dp.size();
    v(int) indegree(n, 0);

    for (int i = 1; i < n; i++)
    {
        for (int x : Adj[i])
        {
            // i -> x
            indegree[x]++;
        }
    }

    int ans = 0;

    queue<int> q;

    for (int i = 1; i < n; i++)
        if (indegree[i] == 1)
        {
            q.push(i);
            dp[i] = 1;
        }

    while (q.size() > 0)
    {

        int f = q.front();
        q.pop();

        for (int nb : Adj[f])
        {
            indegree[nb]--;
            if (dp[nb] == -1 and indegree[nb] == 1)
            {
                dp[nb] = dp[f] + 1;
                q.push(nb);
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;

    int op;
    cin >> op;

    v(int) Adj[n + 1];

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    v(int) dp(n + 1, -1);

    solve(dp, Adj);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] > op)
            ans++;
        // cout << dp[i] << ' ';
    }

    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //