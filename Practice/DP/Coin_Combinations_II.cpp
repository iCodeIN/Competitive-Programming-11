// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
/* author : pasricha_dhruv */
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#include <bits/stdc++.h>
using namespace std;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#define v(Type) vector<Type>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define ff first
#define ss second
#define int long long
#define mod 1000000007ll
#define endl "\n"
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
void solve()
{
    int n, x;
    cin >> n >> x;

    v(int) A(n);
    for (int &x : A)
        cin >> x;

    int dp[2][x + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            int &ans = dp[i & 1][j];

            if (i == 0)
                ans = j == 0;
            else
            {
                int ans1 = dp[(i - 1) & 1][j];
                int ans2 = (A[i - 1] <= j) ? dp[i & 1][j - A[i - 1]] : 0;
                ans = (ans1 + ans2) % mod;
            }
        }
    }

    cout << dp[n & 1][x] << endl;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
