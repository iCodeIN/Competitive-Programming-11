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
int dp[2][1001];
int solve(int n, int k)
{
    for (int pos = n; pos >= 0; pos--)
    {
        for (int prev = k; prev >= 1; prev--)
        {
            int &ans = dp[pos % 2][prev];
            if (pos == n)
                ans = 1;
            else
            {
                ans = dp[(pos + 1) % 2][prev];
                if (prev != k)
                    ans = (ans + dp[pos % 2][prev + 1]) % mod;
            }
        }
    }
    return dp[0][1];
}
void solve()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int ans = solve(2 * m, n);
    cout << ans << endl;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
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