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
    int x;
    cin >> x;

    string s;
    cin >> s;

    v<int> pre(n);
    v<int> suf(n);

    pre[0] = (s[0] == '0');
    suf[n - 1] = (s[n - 1] == '0');

    for (int i = 1; i < n; i++)
        if (s[i] == '1')
            continue;
        else
            pre[i] = 1 + pre[i - 1];

    for (int i = n - 2; i >= 0; i--)
        if (s[i] == '1')
            continue;
        else
            suf[i] = 1 + suf[i + 1];

    v<int> preDP(n, 0);
    v<int> sufDP(n, 0);

    preDP[0] = pre[0] / x;
    sufDP[1] = sufDP[n - 1] / x;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == '1')
            preDP[i] = preDP[i - 1];
        else
        {
            preDP[i] = pre[i] / x;
            int j = i - pre[i];
            if (j >= 0)
                preDP[i] += preDP[j];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == '1')
            sufDP[i] = sufDP[i + 1];
        else
        {
            sufDP[i] = suf[i] / x;
            int j = i + suf[i];
            if (j < n)
                sufDP[i] += sufDP[j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int left = (i == 0) ? 0 : pre[i - 1];
        int right = (i == n - 1) ? 0 : suf[i + 1];

        int cur = (left + right + 1) / x;

        int j1 = i - left - 1;
        int j2 = i + right + 1;

        if (j1 >= 0)
            cur += preDP[j1];
        if (j2 < n)
            cur += sufDP[j2];

        ans = max(ans, cur);
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
