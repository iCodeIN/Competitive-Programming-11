

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


int bs(int n, int x)
{

    int l = 1;
    int r = n + 1;

    while (r - l > 1)
    {

        int m = (l + r) >> 1;

        if ((n / m) > x)
            l = m;
        else
            r = m;
    }
    return l;
}

int f(int n, v(int) & dp, int m)
{
    int x = 1;
    int ans = 0;
    int N = n;
    while (n > 1)
    {

        int n_ = bs(N, x);
        // cout << n << " " << x << " " << n_ << endl;
        ans = (ans + ((n - n_) * dp[x]) % m) % m;

        n = n_;
        x = N / n;
    }
    return ans;
}

void solve()
{
    int n;
    int m;
    cin >> n >> m;

    v(int) dp(n + 1), pre(n + 1);
    dp[0] = pre[0] = 0;
    dp[1] = pre[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int ans = pre[i - 1];

        ans = (ans + f(i, dp, m)) % m;

        dp[i] = ans;
        pre[i] = (pre[i - 1] + dp[i]) % m;
    }

    // for (int x : dp)
    //     cout << x << " ";

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