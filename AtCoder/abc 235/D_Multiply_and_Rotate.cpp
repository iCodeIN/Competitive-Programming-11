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
map<int, int> dp;
string n_;
int solve(int x, int a, int n)
{
    if (x == n)
        return 0;

    if (dp.count(x))
    {
        if (dp[x] == -1)
            return INT_MAX; // not possible
        return dp[x];
    }

    string x_ = to_string(x);

    if (x_.length() > n_.length())
        return INT_MAX;

    int ans = INT_MAX;

    dp[x] = -1; // path m aagya hai but answer nhi nikla

    // choice 1
    ans = solve(x * a, a, n);

    if (x > 10 and x % 10 != 0)
    {
        x_ = x_.back() + x_;
        x_.pop_back();
        // choice2
        int ans2 = solve(stoll(x_), a, n);
        ans = min(ans, ans2);
    }

    if (ans != INT_MAX)
        ans++;

    return dp[x] = ans;
}

void solve()
{

    int a, n;
    cin >> a >> n;
    n_ = to_string(n);
    int ans = solve(1, a, n);

    cout << ((ans == INT_MAX) ? -1 : ans) << endl;
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
// // //  // // //  // // //  // // // // // //  // // // // // /1
