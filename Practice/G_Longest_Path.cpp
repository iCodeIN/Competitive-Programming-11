

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

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

int dfs(int x, v(v(int)) & A, v(int) & dp)
{
    if (dp[x] != -1)
        return dp[x];

    int ans = 0;

    for (int v : A[x])
        ans = max(ans, 1 + dfs(v, A, dp));

    return dp[x] = ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    v(v(int)) A(n + 1);

    while (m--)
    {
        int u, v;
        cin >> u >> v;

        A[u].push_back(v);
    }

    v(int) dp(n + 1, -1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dfs(i, A, dp));

    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //