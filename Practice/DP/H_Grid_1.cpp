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
bool ok(int x, int y, int n, int m)
{
    return x >= 0 and x < n and y >= 0 and y < m;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    v(v(char)) A(n, v(char)(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    int dp[n + 1][m + 1];

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int &ans = dp[i][j];
            ans = 0;
            if (A[i][j] == '#')
                continue;
            if (i == n - 1 and j == m - 1)
                ans = 1;
            else
            {
                int ans1 = ok(i + 1, j, n, m) ? dp[i + 1][j] : 0;
                int ans2 = ok(i, j + 1, n, m) ? dp[i][j + 1] : 0;

                ans = (ans1 + ans2) % mod;
            }
        }
    }
    cout << dp[0][0] << endl;
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
