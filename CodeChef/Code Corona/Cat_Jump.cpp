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
// #define int LL
#define ss second
#define v vector
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int dp[1001];
int solve(v<int> &A, int pos, int k)
{
    if (pos + 1 == A.size())
        return 0;

    if (pos >= A.size())
        return INT_MAX;

    int &ans = dp[pos];
    if (ans != -1)
        return ans;
    ans = INT_MAX;
    int n = A.size();
    for (int i = 1; i <= k and pos + i < n; i++)
    {
        int cur = solve(A, pos + i, k);
        if (cur != INT_MAX)
            cur += abs(A[pos] - A[pos + i]);
        ans = min(ans, cur);
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;

    v<int> A(n);

    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < n; i++)
        dp[i] = -1;

    int ans = solve(A, 0, k);
    cout << ans << endl;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
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