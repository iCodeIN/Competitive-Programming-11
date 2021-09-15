

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

const int N = 1e6;
int dp[N + 1][2];

int f(int h, int w)
{
    if (h == 0)
        return 1ll;

    if (dp[h][w] != -1)
        return dp[h][w];

    int ans = 0;

    if (w == 2)
        for (int i = 1; i <= h; i++)
            ans = (ans + (f(i, 1) * f(h - i, 2)) % mod) % mod;

    for (int i = 1; i <= h; i++)
        ans = (ans + f(h - i, w)) % mod;

    return dp[h][w] = ans;
}

void solve()
{
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    cout << f(n, 2) << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //