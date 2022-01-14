// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
/* author : pasricha_dhruv */
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#include <bits/stdc++.h>
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
using namespace std;
using LL = long long int;
using LD = long double;
using vi = vector<LL>;
using pii = pair<LL, LL>;
const LL mod = 1e9 + 7;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#define all(x) x.begin(), x.end()
#define double LD
#define endl "\n"
#define ff first
#define int LL
#define ss second
#define v vector
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int dp[10][200005];
void solve()
{
    string s;
    cin >> s;
    int m;
    cin >> m;
    int ans = 0;
    for (char ch : s)
    {
        int d = ch - '0';
        ans = (ans + dp[d][m]) % mod;
    }
    cout << ans << endl;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    cin >> t;

    for (int j = 0; j < 200005; j++)
    {
        for (int i = 9; i >= 0; i--)
        {
            int &ans = dp[i][j];
            if (j == 0)
                ans = 1;
            else if (i == 9)
                ans = (dp[0][j - 1] + dp[1][j - 1]) % mod;
            else
                ans = dp[i + 1][j - 1];
        }
    }

    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //