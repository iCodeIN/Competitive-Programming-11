

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
#include <unordered_map>
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

// #define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

int dp[2][10000001];

int solve(v(int) & A, int n, int k)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    dp[i & 1][j] = 0;
                }
                else
                {
                    dp[i & 1][j] = 10000000;
                }
            }
            else
            {
                dp[i & 1][j] = dp[(i - 1) & 1][j];
                if (A[i - 1] <= j)
                    dp[i & 1][j] = 1 + dp[i & 1][j - A[i - 1]];
            }
        }
    }
    return dp[n & 1][k];
}

void solve()
{
    int n;
    cin >> n;

    v(int) F(11);
    int f = 1;
    int i = 2;
    int j = -1;
    while (f <= n)
    {
        F[++j] = f;
        f *= i;
        i++;
    }
    int ans = solve(F, j + 1, n);

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