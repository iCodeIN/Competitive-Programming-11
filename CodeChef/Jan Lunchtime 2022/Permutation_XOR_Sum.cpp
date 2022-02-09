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
// #define int LL
#define ss second
#define v vector
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

int solve(v<int> &A, int n, int f)
{
    if (n == 0)
    {

        int cur = 0;
        n = A.size();
        for (int i = 1; i < n; i++)
        {
            cur += (i ^ A[i]);
        }
        if (f == cur)
        {
            for (int i = 1; i < n; i++)
            {
                cout << A[i] << " ";
            }
            cout << endl;
        }
        return cur;
    }
    int ans = 0;
    for (int i = 1; i < A.size(); i++)
    {
        int &x = A[i];
        if (x == -1)
        {
            x = n;
            ans = max(ans, solve(A, n - 1, f));
            x = -1;
        }
    }
    return ans;
}

int solve(v<int> &A, int n)
{
    if (n == 0)
    {
        int cur = 0;
        n = A.size();
        for (int i = 1; i < n; i++)
        {
            cur += (i ^ A[i]);
        }
        return cur;
    }
    int ans = 0;
    for (int i = 1; i < A.size(); i++)
    {
        int &x = A[i];
        if (x == -1)
        {
            x = n;
            ans = max(ans, solve(A, n - 1));
            x = -1;
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;

    v<int> A(n);

    v<int> c(n + 1, -1);

    int ans = solve(c, n);
    cout << n << ": ->";
    cout << ans << endl;
    solve(c, n, ans);
    // cout << ans << endl;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// 0001                {1, 8}
// 0010
// 0011
// 0100                {4, 11}
// 0101                {5, 10}
// 0110                {6, 11}
// 0111
// 1000     // 0001    {8, 1}
// 1001     // 0110    {9, 6}
// 1010     // 0101    {10. 5}
// 1011     // 0100    {11, 4}

// (8 * 15) +

// 0
// 3 + 3
// 3 + 3 + 0
// 7 + 7 + 3 + 3
// 7 + 7 + 7 + 7 + 0
// 7 + 7 +

// 2 (3)
// 2 ( 7 + 3)
// 2 (7 + 7 )
// 2 (7 + 7 + 7) + 0
// (15 * 2 + 7 *

// 100