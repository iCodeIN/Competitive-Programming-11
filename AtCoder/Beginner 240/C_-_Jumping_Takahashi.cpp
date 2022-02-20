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
        int n, x;
        cin >> n >> x;

        v<pii> A(n);

        for (auto &p : A)
            cin >> p.ff >> p.ss;

        map<int, set<int>> mp;

        queue<pii> q;

        q.push({0, 0});

        while (q.size() > 0)
        {
            auto f = q.front();
            q.pop();

            int pos = f.ff;
            int level = f.ss;

            if (mp[level + 1].count(pos + A[level].ff) == 0)
            {
                if (pos + A[level].ff <= x and level + 1 <= n)
                {
                    mp[level + 1].insert(pos + A[level].ff);
                    q.push({pos + A[level].ff, level + 1});
                }
            }

            if (mp[level + 1].count(pos + A[level].ss) == 0)
            {
                if (pos + A[level].ss <= x and level + 1 <= n)
                {

                    mp[level + 1].insert(pos + A[level].ss);
                    q.push({pos + A[level].ss, level + 1});
                }
            }
        }

        if (mp[n].count(x))
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
