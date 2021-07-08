

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
#include <bits/stdc++.h>
// #include <cmath>
// #include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>
// #include <vector>

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
// 500 * 500 = 125000
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

int pow(int x, int n, int m)
{
    int ans = 1;
    while (n > 0)
    {
        if (n & 1)
            ans = (ans * x) % m;

        x = (x * x) % m;

        n >>= 1;
    }
    return ans;
}

int dp[501][125001];
int solve(int n, int k)
{
    if (k < 0)
        return 0;
    if (n == 0)
        return k == 0;
    if (dp[n][k] != -1)
        return dp[n][k];
    int ans1 = solve(n - 1, k - n);
    int ans2 = solve(n - 1, k);

    return dp[n][k] = (ans1 + ans2) % mod;
}

void solve()
{
    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    if (sum % 2 == 0)
        ans = solve(n, sum / 2);
    ans = (pow(2, mod - 2, mod) * ans) % mod;
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