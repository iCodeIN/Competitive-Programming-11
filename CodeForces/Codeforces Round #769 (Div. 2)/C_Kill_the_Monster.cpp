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
int f(int health, int attack, int freq)
{
    return health - (attack * freq);
}

bool solve(int hc, int dc, int hm, int dm)
{

    int l = 0;
    int r = 1e16;

    while (r - l > 1)
    {
        int m = (l + r) / 2;

        auto ch = f(hc, dm, m);
        auto mon = f(hm, dc, m);
        if (ch <= 0 or mon <= 0)
            r = m;
        else
            l = m;
    }

    // here both positive
    auto c = f(hc, dm, l);
    auto mon = f(hm, dc, l);

    // cout << c << " " << mon << endl;

    bool ans = true;
    mon -= dc;

    if (mon > 0)
        ans = false;

    return ans;
}
void solve()
{
    int hc, dc, hm, dm;
    cin >> hc >> dc >> hm >> dm;

    int k, w, a;
    cin >> k >> w >> a;

    bool ans = false;

    hc += k * a;

    for (int i = 0; i <= k; i++)
    {
        ans = solve(hc, dc, hm, dm);
        if (ans == true)
            break;
        dc += w;
        hc -= a;
    }

    if (ans)
        cout << "YES";
    else
        cout << "NO";

    cout << endl;
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