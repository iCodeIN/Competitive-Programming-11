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
    for (int &x : A)
        cin >> x;

    int prev = -1;
    bool died = false;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 1)
        {
            if (prev == 1)
                ans += 5;
            else
                ans++;
        }
        died = died or (A[i] == 0 and prev == 0);
        prev = A[i];
    }
    if (died)
        ans = -1;

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
