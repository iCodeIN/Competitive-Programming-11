

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
#include <bits/stdc++.h>
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

const int N = 1e5;

struct node
{
    int dp[N + 10];

    node()
    {
        memset(dp, -1, sizeof(dp));
    }
};

int solve(int n, int k, node &x)
{
    // if (n == 0)
    // {
    //     return x.dp[0] = 1;
    // }
    // int &ans = x.dp[n];
    // if (ans != -1)
    //     return ans;
    // int ans1 = solve(n - 1, k, x);
    // int ans2 = (n - k >= 0) ? solve(n - k, k, x) : 0;

    // return ans = (ans1 + ans2) % mod;

    for (int i = 0; i <= n; i++)
    {

        int &ans = x.dp[i];
        if (i == 0)
            ans = 1;
        else
        {
            int ans1 = x.dp[i - 1];
            int ans2 = (i - k >= 0) ? x.dp[i - k] : 0;
            ans = (ans1 + ans2) % mod;
        }
    }
    return x.dp[n];
}

void solve()
{
    node x;
    int q, k;
    cin >> q >> k;
    solve(N, k, x);

    for (int i = 1; i <= N; i++)
    {
        x.dp[i] = (x.dp[i] + x.dp[i - 1]) % mod;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = x.dp[r] - x.dp[l - 1];
        ans = (ans + mod) % mod;
        cout << ans << endl;
    }
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //