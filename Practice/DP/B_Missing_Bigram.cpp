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
    n -= 2;
    v(string) A(n);
    for (auto &x : A)
        cin >> x;
    string ans = "";
    ans = A[0][0];
    auto &s = A;
    int ca = 0;
    int cb = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1][1] != s[i][0])
        {
            ans += s[i - 1][1];
            ans += s[i][0];
        }
        else
        {
            ans += s[i][0];
        }
    }
    ans += A[n - 1][1];
    for (char x : ans)
        ca += (x == 'a'), cb += (x == 'b');
    if (ans.size() != n + 2)
        ans += (ca <= cb) ? 'a' : 'b';
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
