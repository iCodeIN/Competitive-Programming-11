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
int pow(int x, int n, int m)
{
    int ans = 1;

    while (n)
    {
        if (n % 2ll == 1)
            ans = (ans * x) % m;

        n /= 2ll;

        x = (x * x) % m;
    }

    return ans;
}
class Solution
{

public:
    static void solve()
    {
        int n, m, k, q;
        cin >> n >> m >> k >> q;

        map<int, int> row, col;

        v<v<int>> queries(q, v<int>(2));

        for (int i = 0; i < q; i++)
        {
            int x, y;
            cin >> x >> y;
            queries[i][0] = x;
            queries[i][1] = y;
        }

        int rowLeft = n;
        int colLeft = m;

        for (int i = q - 1; i >= 0; i--)
        {
            int x = queries[i][0];
            int y = queries[i][1];
            if (row.count(x) == 0 and (rowLeft > 0 and colLeft > 0))
                row[x] = i, rowLeft--;
            if (col.count(y) == 0 and (rowLeft > 0 and colLeft > 0))
                col[y] = i, colLeft--;
        }

        set<int> st;

        for (auto r : row)
            st.insert(r.ss);

        for (auto c : col)
            st.insert(c.ss);

        int options = st.size();

        int ans = pow(k, options, 998244353ll);

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
