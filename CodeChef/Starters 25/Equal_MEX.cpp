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
        v<int> A(2 * n);
        for (int &x : A)
            cin >> x;
        map<int, int> mp;
        for (int &x : A)
            mp[x]++;
        bool ans = true;

        for (int i = 0; i < n; i++)
        {
            if (mp[i] == 0)
                break;

            if (mp[i] == 1)
            {
                ans = false;
                break;
            }
        }

        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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
