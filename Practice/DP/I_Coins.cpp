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
v<v<LD>> dp;
LD solve(v<LD> &A, int n, int diff)
{
    if (n == 0)
        return diff > 0;

    if (dp[n][diff + A.size()] != -1)
        return dp[n][diff + A.size()];

    auto ans1 = solve(A, n - 1, diff + 1) * A[n - 1];
    auto ans2 = solve(A, n - 1, diff - 1) * (1 - A[n - 1]);

    return dp[n][diff + A.size()] = ans1 + ans2;
}
void solve()
{
    int n;
    cin >> n;

    v<LD> A(n);

    for (int i = 0; i < n; i++)
        cin >> A[i];
    
    dp.assign(n + 1, v<LD>(2 * n + 10, -1));

    auto ans = solve(A, n, 0);
    
    cout << setprecision(12);
    
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