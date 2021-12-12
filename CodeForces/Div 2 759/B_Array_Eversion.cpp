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
void solve()
{
    int n;
    cin >> n;

    v(int) A(n);

    for (int i = 0; i < n; i++)
        cin >> A[i];

    int cur = A[n - 1];
    int ans = 0;
    for (int i = n - 2; i >= 0; i--)
        if (A[i] > cur)
            cur = A[i], ans++;
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
