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
    string s;
    cin >> s;

    int n = s.length();
    bool dp[n + 1][n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i + 1; j++)
        {
            if (j <= 1)
            {
                dp[i][j] = true;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j - 2] and s[i] == s[i - j + 1]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;

        while (j >= 0 and dp[j][i] == false)
            j--;

        if (j >= 0)
            ans++;
    }
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