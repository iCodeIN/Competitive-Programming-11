

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

int pow(int x, int n, int m)
{

    int ans = 1;

    while (n)
    {
        if (n & 1)
            ans = (ans * x) % m;

        n >>= 1;
        x = (x * x) % m;
    }
    return ans;
}

const int N = 2 * 1e5 + 10;
int dp[N + 1];
int p[N + 1];
int solve(int k, int n)
{

    if (k == 0)
        return 1;

    if (dp[k] != -1)
        return dp[k];

    // 1
    int ans1 = 0;
    if (n & 1)
        ans1 = solve(k - 1, n);
    else
        ans1 = pow(2, n * (k - 1), mod);

    //0
    int ans2 = 0;
    if (n & 1)
        ans2 = p[n - 1];
    else
        ans2 = (p[n - 1] - 1 + mod) % mod;

    ans2 = (ans2 * solve(k - 1, n)) % mod;

    return dp[k] = (ans1 + ans2) % mod;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= k; i++)
        dp[i] = -1;
    int ans = solve(k, n);

    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    p[0] = 1;
    for (int i = 1; i <= N; i++)
        p[i] = (2 * p[i - 1]) % mod;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //