

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
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

void solve()
{

    int n;
    cin >> n;

    v(int) A(n), B(n);

    for (int &x : A)
        cin >> x;

    for (int &x : B)
        cin >> x;

    int dp[2][5001];

    for (int i = 0; i <= n; i++)
    {

        for (int j = 0; j <= 5000; j++)
        {
            if (i == 0)
            {
                dp[i & 1][j] = (j == 0);
            }
            else
            {

                dp[i & 1][j] = dp[(i - 1) & 1][j];

                if (B[i - 1] <= j)
                    dp[i & 1][j] = (dp[i & 1][j] + dp[(i - 1) & 1][j - B[i - 1]]) % mod;
            }
        }
    }

    sort(all(A));
    int ans = 0;
    for (int i = 1; i <= 3; i++)
    {

        int x = lower_bound(A.begin(), A.end(), i) - A.begin();
        // cout << ans << " ";
        ans = (ans + (dp[n & 1][i] * (n - x)) % mod) % mod;
        cout << dp[n & 1][i] << ' ';
        cout << n - x << " ";
        cout << endl;
    }
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