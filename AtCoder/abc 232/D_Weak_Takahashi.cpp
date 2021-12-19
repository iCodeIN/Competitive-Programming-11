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

int solve(v<string> &A, int x, int y, int m, int n, v<v<int>> &dp)
{
    if (x >= m or y >= n)
        return 0;

    if (A[x][y] == '#')
        return 0;
    int &ans = dp[x][y];
    if (ans != -1)
        return ans;
    ans = 1 + max(solve(A, x + 1, y, m, n, dp), solve(A, x, y + 1, m, n, dp));
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    v<string> A(n);
    for (auto &s : A)
        cin >> s;
    v<v<int>> dp(n, v<int>(m, -1));
    int res = solve(A, 0, 0, n, m, dp);
    cout << res << endl;
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