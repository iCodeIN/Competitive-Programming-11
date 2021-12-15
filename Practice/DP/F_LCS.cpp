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
    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            int &ans = dp[i][j];

            if (i == 0 or j == 0)
                ans = 0;
            else if (a[i - 1] == b[j - 1])
                ans = 1 + dp[i - 1][j - 1];
            else
            {
                int ans1 = dp[i - 1][j];
                int ans2 = dp[i][j - 1];
                ans = max(ans1, ans2);
            }
        }
    }

    int i = n;
    int j = m;

    string s = "";

    while (i > 0 and j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            s += a[i - 1];
            i--;
            j--;
        }
        else if (dp[i][j] == dp[i - 1][j])
            i--;
        else
            j--;
    }
    reverse(all(s));
    cout << s << endl;
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
