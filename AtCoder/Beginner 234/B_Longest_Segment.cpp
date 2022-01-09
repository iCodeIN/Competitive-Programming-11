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
LD f(LD x1, LD y1, LD x2, LD y2)
{
    LD ans = (x2 - x1) * (x2 - x1);
    ans += (y2 - y1) * (y2 - y1);
    return ans;
}

void solve()
{
    int n;
    cin >> n;

    v<LD> X(n), Y(n);
    for (int i = 0; i < n; i++)
        cin >> X[i] >> Y[i];

    LD ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans = max(ans, f(X[i], Y[i], X[j], Y[j]));
    cout << setprecision(12);
    cout << sqrt(ans) << endl;
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