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
bool good(string &s, int k, int len)
{

    int op = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        int current = s[i] - '0';
        current += op;
        current %= 10;
        int here = (10 - current) % 10;
        op += here;
    }

    return op <= k;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int l = -1;
    int r = n + 1;

    while (r - l > 1)
    {
        int m = (l + r) / 2;

        if (good(s, k, m))
            l = m;
        else
            r = m;
    }

    cout << l << endl;
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