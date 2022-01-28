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

class Solution
{
    string a;
    v<int> sufA;
    string b;
    v<int> sufB;
    int n;
    v<v<int>> dp;

    int solve(int i, int j)
    {
        if (i == n and j == n)
            return 0;

        int &ans = dp[i][j];

        if (ans != -1)
            return ans;

        ans = INT_MAX;

        // move i forward
        if (i < n)
        {
            int ans1 = solve(i + 1, j);
            if (a[i] == '1')
            {
                ans1 += (sufA[i + 1] + sufB[j]);
            }
            ans = min(ans, ans1);
        }

        // move j forward
        if (j < n)
        {
            int ans2 = solve(i, j + 1);
            if (b[j] == '1')
            {
                ans2 += (sufA[i] + sufB[j + 1]);
            }
            ans = min(ans, ans2);
        }

        return ans;
    }

public:
    void solve()
    {
        cin >> n;

        cin >> a >> b;

        sufA.resize(n + 10);
        sufB.resize(n + 10);

        dp.assign(n + 10, v<int>(n + 10, -1));

        for (int i = n - 1; i >= 0; i--)
        {
            sufA[i] = (sufA[i + 1] + (a[i] == '0'));
            sufB[i] = (sufB[i + 1] + (b[i] == '0'));
        }

        int ans = solve(0, 0);

        cout << ans << endl;
    }
} sol;

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        sol.solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
