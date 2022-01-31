// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
/* author : pasricha_dhruv */
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#include <bits/stdc++.h>
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
using namespace std;
using LL = long long int;
using LD = long double;
using vi = vector<int>;
using pii = pair<int, int>;
const int mod = 1e9 + 7;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#define aint(x) x.begin(), x.end()
#define double LD
#define endl "\n"
#define ff first
// #define int LL
#define ss second
#define v vector
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
const int N = 1e3 + 10;
int height[N + 1];
void pre()
{
    height[1] = 0;
    for (int i = 1; i <= N; i++)
    {
        if (height[i] == INT_MAX)
            continue;
        for (int j = 1; j <= i; j++)
        {
            int cur = i + (i / j);
            if (cur > 0 and cur <= N)
                height[cur] = min(height[i] + 1, height[cur]);
        }
    }
}

static int dp[1001][12001];
int solve(v<int> &weight, v<int> &value, int n, int current, int k)
{
    if (n == 0)
        return 0;

    if (dp[n][current] != -1)
        return dp[n][current];

    int ans1 = solve(weight, value, n - 1, current, k);
    int ans2 = INT_MIN;

    if (weight[n - 1] + current <= k)
        ans2 = solve(weight, value, n - 1, current + weight[n - 1], k) + value[n - 1];

    return dp[n][current] = max(ans1, ans2);
}

void solve()
{
    int n;
    cin >> n;

    int k;
    cin >> k;

    v<int> B(n);
    v<int> C(n);

    for (int &x : B)
        cin >> x;

    for (int &x : C)
        cin >> x;

    for (int &x : B)
        x = height[x];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= 12 * n; j++)
            dp[i][j] = -1;

    int ans = solve(B, C, n, 0, k);

    cout << ans << endl;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    for (int i = 1; i <= N; i++)
        height[i] = INT_MAX;
    pre();
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
