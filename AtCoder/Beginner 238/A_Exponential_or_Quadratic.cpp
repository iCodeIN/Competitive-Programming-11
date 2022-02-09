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

public:
    static void solve()
    {
        int n;
        cin >> n;

        LD RHS = 2 * log2(n);

        int LHS = n;

        if (LHS > RHS)
            cout << "Yes";
        else
            cout << "No";
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
bool TestCases::multiple = false;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    TestCases::solve();
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
