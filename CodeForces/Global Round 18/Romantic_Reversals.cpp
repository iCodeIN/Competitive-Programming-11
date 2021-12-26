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
    int n;
    cin >> n;

    int k;
    cin >> k;
    string s;
    cin >> s;

    vector<int> A(n);
    k--;
    for (int i = k + 1; i < n; i++)
        A[i] = i;

    int i = 0;

    int idx = k;
    while (idx >= 0)
    {
        A[i++] = idx;
        idx -= 2;
    }
    if (k % 2 == 0)
        idx = 1;
    else
        idx = 0;
    while (idx <= k)
    {
        A[i++] = idx;
        idx += 2;
    }

    string ans = s;
    for (int i = 0; i < n; i++)
        ans[A[i]] = s[i];
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