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
    int n;
    cin >> n;

    int k;
    cin >> k;

    v<int> A(n);
    for (int &x : A)
        cin >> x;

    v<v<int>> dp(2, v<int>(k + 1));
    int ans = 0;

    for (int i = n; i >= 0; i--)
    {
        v<int> &current = dp[i & 1];
        v<int> &prev = dp[(i - 1) & 1];

        for (int j = 0; j <= k; j++)
        {

            int &ans = current[j];
            if (i == n)
                ans = j == 0;
            else
            {
                // j ........ j - a[i]
                int s = max(0ll, j - A[i]);
                int e = j;
                ans = (s == 0) ? prev[e] : prev[e] - prev[s - 1];
                ans = (ans + mod) % mod;
            }
        }
        if (i > 0)
            for (int i = 1; i <= k; i++)
                current[i] = (current[i - 1] + current[i]) % mod;
    }
    cout << dp[0][k] << endl;
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