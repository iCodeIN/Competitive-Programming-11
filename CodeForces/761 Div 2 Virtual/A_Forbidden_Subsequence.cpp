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
    string s, t;
    cin >> s >> t;

    sort(all(s));

    if (t == "abc")
    {
        int a = 0;
        int b = 0;
        int c = 0;
        for (char ch : s)
            a += (ch == 'a'), b += (ch == 'b'), c += (ch == 'c');

        if (a > 0 and b > 0 and c > 0)
        {
            int idx = a + b + c;
            while (a--)
                cout << 'a';
            while (c--)
                cout << 'c';
            while (b--)
                cout << 'b';
            while (idx < s.length())
                cout << s[idx++];
        }
        else
        {
            cout << s;
        }
    }
    else
    {
        cout << s;
    }
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