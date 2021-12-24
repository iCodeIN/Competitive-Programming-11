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
const int N = 2 * 1e5;
v<int> A[32];

void solve()
{
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for (int i = 0; i < 32; i++)
        ans = max(ans, A[i][r] - A[i][l - 1]);
    ans = (r - l + 1) - ans;
    cout << ans << endl;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    for (int i = 0; i < 32; i++)
        A[i].resize(N + 1);

    for (int j = 1; j <= N; j++)
    {
        for (int i = 0; i < 32; i++)
            A[i][j] = (j & (1 << i)) != 0;
    }

    for (int i = 0; i < 32; i++)
        for (int j = 1; j <= N; j++)
            A[i][j] += A[i][j - 1];

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