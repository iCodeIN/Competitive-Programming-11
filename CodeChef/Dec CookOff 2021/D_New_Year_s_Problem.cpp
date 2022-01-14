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
void solve()
{
    int m, n;
    cin >> m >> n;

    v<v<int>> A(m, v<int>(n));
    int ans = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    v<int> best(n); // {val, shop}
    set<int> shops;
    for (int j = 0; j < n; j++)
    {

        for (int i = 0; i < m; i++)
        {
            if (A[i][j] >= A[best[j]][j])
                best[j] = i;
        }
        shops.insert(best[j]);
    }

    if (shops.size() <= n - 1)
    {
        // choose the best
        ans = A[best[0]][0];
        for (int j = 1; j < n; j++)
            ans = min(ans, A[best[j]][j]);
    }
    else
    {
        for (int j = 0; j < n; j++)
        {
            // discarding best[j]
            int cur = INT_MAX;
            for (int s = 0; s < n; s++)
                if (s != j)
                    cur = min(cur, A[best[s]][s]);
            int rem = 0;
            for (int s = 0; s < n; s++)
                if (s != j)
                    rem = max(rem, A[best[s]][j]);
            cur = min(cur, rem);
            ans = max(ans, cur);
        }
    }
    cout << ans << endl;
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