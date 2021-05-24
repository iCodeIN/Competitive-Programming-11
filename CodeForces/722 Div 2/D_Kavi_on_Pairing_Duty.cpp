

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
#define mod 998244353ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

v(int) dp(1000000);

int f(int fac)
{
    if (fac - 2 > 0)
        return dp[fac - 2];
    return 1;
}

int div_(int n, int x)
{
    int ans = 0;

    for (int i = 1; i * i <= n and i <= x; i++)
    {
        if (n % i == 0)
        {
            if (i % 2 == 0)
                ans = (ans + f(i)) % mod;
            if (i * i != n and n <= x * i and (n / i) % 2 == 0)
                ans = (ans + f(n / i)) % mod;
        }
    }
    // cout << n << " : " << ans << endl;
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    int pre = 5;
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (pre + div_(2 * i, i)) % mod;
        pre = (pre + dp[i]) % mod;
    }

    cout << dp[n] << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //