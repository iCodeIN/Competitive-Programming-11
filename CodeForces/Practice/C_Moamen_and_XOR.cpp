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
// Precomputation
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
const int N = 2 * 1e5 + 10;
int dp[N + 1][2];
int pow__[N + 1];
class PreCompute
{
public:
    static void preCompute()
    {
        pow__[0] = 1;

        for (int i = 1; i <= N; i++)
        {
            pow__[i] = pow__[i - 1] * 2;
            pow__[i] %= mod;
        }
    }
};
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
// Solution
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

class Solution
{
    static int solve(int pos, bool prev, int k, int n)
    {
        if (pos == k)
            return 1;

        int &ans = dp[pos][prev];

        if (ans != -1)
            return ans;

        ans = 0;

        if (prev)
        {
            ans = pow__[n] * solve(pos + 1, prev, k, n);
            ans %= mod;
        }
        else
        {
            // make greater here
            if (n % 2 == 0)
            {
                ans = solve(pos + 1, true, k, n);
            }
            else
            {
                ans = 0; // no possible way
            }

            // keep it same
            if (n % 2 == 0)
            {
                // 0, 2, 4, n - 2
                ans = (ans + (((pow__[n - 1] - 1) + mod) % mod * solve(pos + 1, false, k, n)) % mod) % mod;
            }
            else
            {
                // even one's
                int ans1 = (pow__[n - 1] * solve(pos + 1, false, k, n)) % mod;

                // all one's
                int ans2 = solve(pos + 1, false, k, n);

                ans = (ans + ans1 + ans2) % mod;
            }
        }

        return ans;
    }

public:
    static void solve()
    {
        int n, k;
        cin >> n >> k;

        memset(dp, -1, sizeof(dp));

        int ans = solve(0, false, k, n);

        cout << ans << endl;
    }
};
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
// TestCases
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
class TestCases
{
public:
    static bool multiple;

    static void solve()
    {
        int t = 1;
        PreCompute::preCompute();
        multiple and cin >> t;
        for (int i = 1; i <= t; i++)
        {
            // cout << "Case #" << i << ": ";
            Solution::solve();
        }
    }
};
bool TestCases::multiple = true;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    TestCases::solve();
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
