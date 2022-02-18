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
class PreCompute
{
public:
    static void preCompute()
    {
    }
};
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
// Solution
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

const int N = 2 * 1e5 + 10;
int dp[N + 1][2][2][2];

class Solution
{

    static int solve(v<int> &A, int pos, bool started, bool rem, int startedAt)
    {

        if (pos == A.size())
            return (started) ? INT_MIN : 0;

        int &ans = dp[pos][started][rem][startedAt];

        if (ans != -1)
            return ans;

        ans = INT_MIN;

        if (started)
        {
            // end here
            int ans1 = INT_MIN;
            if (pos % 2 != startedAt)
                ans1 = solve(A, pos + 1, false, false, 0);

            // don't end here
            int ans2 = solve(A, pos + 1, true, false, startedAt);

            ans = max(ans1, ans2);

            if (ans >= 0 and pos % 2 == 1)
                ans += A[pos];
        }
        else
        {
            // don't start
            int ans1 = solve(A, pos + 1, started, rem, startedAt);
            if (ans1 >= 0 and pos % 2 == 0)
                ans1 += A[pos];

            int ans2 = INT_MIN;
            // start
            if (rem)
            {
                ans2 = solve(A, pos + 1, true, false, pos % 2);

                if (ans2 >= 0 and pos % 2 == 1)
                    ans2 += A[pos];
            }

            ans = max(ans1, ans2);
        }

        return ans;
    }

public:
    static void solve()
    {
        int n;
        cin >> n;

        v<int> A(n);

        for (int i = 0; i < n; i++)
            cin >> A[i];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    for (int p = 0; p < 2; p++)
                        dp[i][j][k][p] = -1;

        int ans = solve(A, 0, false, true, 0);

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
        // PreCompute::preCompute();
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
