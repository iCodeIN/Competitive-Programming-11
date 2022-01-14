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
int nodes[61];
class Solution
{
    int n;
    int m;
    v<v<int>> dp;

    int power(int x, int n)
    {
        int ans = 1;
        while (n)
        {
            if (n & 1)
                ans = (ans * x) % mod;

            n /= 2;
            x = (x * x) % mod;
        }
        return ans;
    }

    int solve(int level, int prev)
    {
        int res = 0;
        for (int i = n + 1; i >= 1; i--)
        {

            if (i == n + 1)
            {
                for (int j = m; j >= 1; j--)
                {
                    dp[i][j] = 1;
                }
            }
            else if (i == 1)
            {
                for (int j = 1; j <= m; j++)
                {
                    int &ans = dp[i][j];
                    ans = dp[i + 1][j];
                    ans = pow(ans, nodes[i]);
                    res = (ans + res) % mod;
                }
            }
            else if (i % 2 == 0)
            {
                for (int j = m - 1; j >= 1; j--)
                {
                    int &ans = dp[i][j];
                    ans = dp[i + 1][j + 1];
                    ans = pow(ans, nodes[i]);
                }
                for (int j = 1; j <= m + 1; j++)
                    dp[i][j] = (dp[i][j - 1] + dp[i][j]) % mod;
            }
            else
            {
                for (int j = m + 1; j >= 2; j--)
                {
                    int &ans = dp[i][j];
                    ans = dp[i + 1][j - 1];
                    ans = pow(ans, nodes[i]);
                }
                for (int j = m; j >= 0; j--)
                    dp[i][j] = (dp[i][j] + dp[i][j + 1]) % mod;
            }
        }
        return res;
    }

public:
    Solution()
    {
        cin >> n >> m;
        n = log2(n + 1);
        dp.assign(n + 2, v<int>(m + 2, 0));
    }

    int solve()
    {
        return solve(1, m + 1);
    }
};

void solve()
{
    Solution sol;
    cout << sol.solve() << endl;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    nodes[1] = 1;
    for (int i = 2; i <= 60; i++)
        nodes[i] = (2 * nodes[i - 1]) % mod;
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //