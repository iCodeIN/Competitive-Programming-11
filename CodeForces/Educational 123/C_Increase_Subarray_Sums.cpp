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
int dp[5001][5001];

class Solution
{

public:
    static void solve()
    {
        int n;
        cin >> n;

        int x;
        cin >> x;

        v<int> A(n);

        for (int i = 0; i < n; i++)
            cin >> A[i];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                int &ans = dp[i][j];

                if (j == 0)
                {
                    ans = A[i];
                    if (i > 0)
                        ans = max(A[i], A[i] + dp[i - 1][j]);
                }
                else if (i == 0)
                    ans = A[i] + x;
                else
                {
                    int ans1 = A[i] + dp[i - 1][j];
                    int ans2 = A[i] + x + dp[i - 1][j - 1];
                    int ans3 = A[i] + x;

                    ans = max({ans1, ans2, ans3});
                }
            }
        }

        for (int k = 0; k <= n; k++)
        {
            int ans = 0;
            for (int i = 0; i < n; i++)
                ans = max(ans, dp[i][k]);

            cout << ans << " ";
        }

        cout << endl;
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
