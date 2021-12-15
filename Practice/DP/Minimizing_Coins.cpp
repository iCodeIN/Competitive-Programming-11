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
int solve(v(int) & A, int target)
{

    int dp[2][target + 1];

    for (int n = 0; n <= A.size(); n++)
    {
        for (int x = 0; x <= target; x++)
        {
            int &ans = dp[n & 1][x];

            if (x == 0)
                ans = 0;
            else if (n == 0)
                ans = INT_MAX;
            else
            {

                int ans1 = (x >= A[n - 1]) ? 1 + dp[n & 1][x - A[n - 1]] : INT_MAX;
                int ans2 = dp[(n - 1) & 1][x];

                ans = min(ans1, ans2);
            }
        }
    }
    return dp[A.size() & 1][target];
}

void solve()
{
    int n, x;
    cin >> n >> x;

    v(int) A(n);
    for (int &x : A)
        cin >> x;

    int ans = solve(A, x);
    if (ans == INT_MAX)
        ans = -1;
    cout << ans << endl;
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
