// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
/* author : pasricha_dhruv */
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#include <bits/stdc++.h>
using namespace std;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#define v(Type) vector<Type>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define ff first
#define ss second
#define int long long
#define mod 1000000007ll
#define endl "\n"
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

int gcd(int a, int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

void solve()
{
    int n;
    cin >> n;
    v(int) A(n);
    for (auto &x : A)
        cin >> x;
    int g1 = 0;
    int g2 = 0;
    for (int i = 0; i < n; i++)
        if (i & 1)
            g1 = gcd(g1, A[i]);
        else
            g2 = gcd(g2, A[i]);
    int ans = 0;

    // cout << g1 << " " << g2 << endl;

    bool ans1 = true;
    bool ans2 = true;

    for (int i = 0; i < n; i += 2)
        ans1 = ans1 and (A[i] % g1 != 0);
    for (int i = 1; i < n; i += 2)
        ans2 = ans2 and (A[i] % g2 != 0);
    // cout << ans1 << " " << ans2 << endl;
    if (ans1)
        ans = g1;
    else if (ans2)
        ans = g2;
    cout << ans << endl;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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
