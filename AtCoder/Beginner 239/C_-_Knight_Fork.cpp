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
    static bool ok(int x1, int y1, int x2, int y2)
    {
        int x = x1 - x2;
        int y = y1 - y2;

        return (x * x) + (y * y) == 5;
    }

public:
    static void solve()
    {

        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        int dx[] = {-1, 1};
        int dy[] = {-2, 2};

        bool ans = false;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int x = dx[i] + x1;
                int y = dy[j] + y1;
                ans |= ok(x2, y2, x, y);
                x = dy[j] + x1;
                y = dx[i] + y1;
                ans |= ok(x2, y2, x, y);
            }
        }

        swap(x1, x2);
        swap(y1, y2);

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int x = dx[i] + x1;
                int y = dy[j] + y1;
                ans |= ok(x2, y2, x, y);
                x = dy[j] + x1;
                y = dx[i] + y1;
                ans |= ok(x2, y2, x, y);
            }
        }

        if (ans)
            cout << "Yes";
        else
            cout << "No";

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
bool TestCases::multiple = false;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    TestCases::solve();
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
