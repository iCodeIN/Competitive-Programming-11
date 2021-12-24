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

int solve(int a, int b, int c, int d, map<int, int> mp[])
{
    // cout << b << c << " " << endl;
    if (b == 0 and c == 0)
        return 0;

    if (mp[b][c] == -1)
        return INT_MAX;

    mp[b][c] = -1;

    int ans1 = (a > 0) ? solve(1 + c, d, a - 1, b, mp) : INT_MAX;
    int ans2 = (b > 0) ? solve(c, 1 + d, a, b - 1, mp) : INT_MAX;

    mp[b][c] = min(ans1, ans2);

    if (mp[b][c] != INT_MAX)
        mp[b][c]++;

    return mp[b][c];
}

void solve()
{
    int n;
    cin >> n;

    string s;
    string t;
    cin >> s >> t;

    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0' and t[i] == '0')
            d++;
        else if (s[i] == '0' and t[i] == '1')
            c++;
        else if (s[i] == '1' and t[i] == '0')
            b++;
        else
            a++;
    }

    s = "";
    t = "";

    a = b = c = d = 10000;
    while (a--)
        s += '0', t += '1';
    while (b--)
        s += '1', t += '1';
    while (c--)
        s += '1', t += '0';
    while (d--)
        s += '0', t += '0';

    cout << s << endl;
    cout << t << endl;
    n = a + b + c + d;

    // map<int, int> mp[n + 1];
    // int ans = solve(a, b, c, d, mp);
    // if (ans == INT_MAX)
    //     ans = -1;
    // cout << "ans found";
    // cout << ans << endl;
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