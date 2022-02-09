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
// 0.....................2*n-1
int solve(v<v<int>> &A, int n, v<bool> &choosen, int current)
{
    if (n == 0)
        return current;

    if (choosen[n - 1])
        return solve(A, n - 1, choosen, current);

    int ans = 0;
    choosen[n - 1] = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (not choosen[i])
        {
            choosen[i] = true;
            ans = max(ans, solve(A, n - 1, choosen, current ^ A[i][n - 1]));
            choosen[i] = false;
        }
    }
    choosen[n - 1] = false;
    return ans;
}

void solve()
{
    int n;
    cin >> n;

    n *= 2;
    v<v<int>> A(n, v<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            cin >> A[i][j];
    }

    v<bool> choosen(n, false);
    int ans = solve(A, n, choosen, 0);
    cout << ans << endl;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //