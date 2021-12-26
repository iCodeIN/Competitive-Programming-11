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
    string s;
    cin >> s;

    int n = s.size();
    v<int> Pre(n);

    Pre[0] = s[0] - '0';
    for (int i = 1; i < n; i++)
        Pre[i] = Pre[i - 1] + s[i] - '0';

    string ans = "";
    int carry = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int current = Pre[i] + carry;
        ans += (char)((current % 10) + '0');
        carry = current / 10;
    }
    while (carry)
    {
        ans += (char)((carry % 10) + '0');
        carry /= 10;
    }
    reverse(all(ans));
    cout << ans << endl;
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