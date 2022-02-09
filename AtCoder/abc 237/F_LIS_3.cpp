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
const LL mod = 998244353;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#define all(x) x.begin(), x.end()
#define double LD
#define endl "\n"
#define ff first
#define int LL
#define ss second
#define v vector
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int dp[1001][12][12][12];
int solve(int pos, int n, int m, int v0, int v1, int v2)
{
    if (pos == n)
    {
        return v2 < m + 1;
    }

    int &ans = dp[pos][v0][v1][v2];

    if (ans != -1)
        return ans;

    ans = 0;

    for (int i = 1; i <= m; i++)
    {

        int v0_ = v0;
        int v1_ = v1;
        int v2_ = v2;

        if (v0 >= i)
            v0_ = i;
        else if (v1 >= i)
            v1_ = i;
        else if (v2 >= i)
            v2_ = i;
        else
            break;

        ans = (ans + solve(pos + 1, n, m, v0_, v1_, v2_)) % mod;
    }

    return ans;
}
void solve()
{
    int n;
    cin >> n;

    int m;
    cin >> m;
    memset(dp, -1, sizeof(dp));
    int ans = solve(0, n, m, m + 1, m + 1, m + 1);

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
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //\