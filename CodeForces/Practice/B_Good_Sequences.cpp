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
const int N = 1e5;
int spf[N + 10];
class PreCompute
{
public:
    static void preCompute()
    {
        for (int i = 0; i <= N; i++)
            spf[i] = i;

        for (int i = 2; i * i <= N; i++)
            if (spf[i] == i)
                for (int j = i * i; j <= N; j += i)
                    spf[j] = min(spf[j], i);
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
        v<int> A(n);

        for (int &x : A)
            cin >> x;

        map<int, int> mp;

        for (int x : A)
        {
            int mx = 0;
            int temp = x;

            while (x != 1)
            {
                mx = max(mp[spf[x]], mx);
                x /= spf[x];
            }

            x = temp;

            while (x != 1)
            {
                mp[spf[x]] = mx + 1;
                x /= spf[x];
            }
        }

        int ans = 1;

        for (auto itr : mp)
            ans = max(ans, itr.ss);

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
bool TestCases::multiple = false;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    TestCases::solve();
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
