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
class Solution
{
    v<bool> AND, SUM;
    int dp[62][2];

    bool solve(int pos, int carry)
    {

        if (pos == 62)
        {
            return carry == 0;
        }
        if (dp[pos][carry] != -1)
            return dp[pos][carry];
        bool ans = false;

        if (AND[pos] == 1)
        {
            // both 1

            int current = (2 + carry);
            if (SUM[pos] == current % 2)
                ans = solve(pos + 1, current / 2);
        }
        else
        {

            pii temp[2] = {{0, 0}, {1, 0}};

            for (int i = 0; i < 2; i++)
            {
                int current = (temp[i].ff + temp[i].ss + carry);

                if (current % 2 == SUM[pos])
                    ans |= solve(pos + 1, current / 2);
            }
        }

        return dp[pos][carry] = ans;
    }

public:
    void solve()
    {
        int _and, _sum;
        cin >> _and >> _sum;

        AND.assign(62, 0);
        SUM.assign(62, 0);

        for (int i = 0; i <= 61; i++)
            if ((1ll << i) & _and)
                AND[i] = 1;

        for (int i = 0; i <= 61; i++)
            if ((1ll << i) & _sum)
                SUM[i] = 1;

        memset(dp, -1, sizeof(dp));

        bool ans = solve(0, 0);

        if (ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
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
            Solution obj;
            obj.solve();
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
