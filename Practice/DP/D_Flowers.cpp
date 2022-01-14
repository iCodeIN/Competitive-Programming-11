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
void solve()
{
    int q;
    cin >> q;

    int k;
    cin >> k;

    const int N = 1e5;
    int dp[N + 1];

    for (int i = 0; i <= N; i++)
    {
        int &ans = dp[i];
        if (i == 0)
            ans = 1;
        else
        {
            // 'R'
            int ans1 = dp[i - 1];
            // 'W'
            int ans2 = (i >= k) ? dp[i - k] : 0;

            ans = (ans1 + ans2) % mod;
        }
    }

    for (int i = 1; i <= N; i++)
        dp[i] = (dp[i] + dp[i - 1]) % mod;

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int ans = dp[r] - dp[l - 1];
        ans = (ans + mod) % mod;
        cout << ans << endl;
    }
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