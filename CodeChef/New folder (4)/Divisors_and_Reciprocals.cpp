// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
/* author : pasricha_dhruv */
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#include <iostream>
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
using namespace std;
using LL = long long int;
using LD = long double;
// using vi = vector<LL>;
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
bool ok(int n, int x)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            x -= i;
            if (n != i * i)
                x -= (n / i);
        }
        if (x < 0)
            return false;
    }
    return x == 0;
}

void solve()
{
    LL x, a, b;
    cin >> x >> a >> b;

    LL num = b * x;
    LL ans = -1;

    if (num % a == 0)
    {
        ans = num / a;
        if (not ok(ans, x))
            ans = -1;
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