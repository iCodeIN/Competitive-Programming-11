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

    int n1 = s.length();
    int n2 = t.length();
    bool ok = 0;
    if (n1 == n2)
    {
        ok = 1;
        set<int> st;
        for (int i = 0; i < n1; i++)
        {
            int cur = 0;
            if (t[i] >= s[i])
                cur = t[i] - s[i];
            else
                cur = ('z' - s[i]) + 1 + (t[i] - 'a');

            st.insert(cur);
        }
        ok = st.size() == 1;
    }
    if (ok)
        cout << "Yes";
    else
        cout << "No";
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