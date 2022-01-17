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
const LL mod = 998244353;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#define all(x) x.begin(), x.end()
#define double LD
#define endl "\n"
#define ff first
#define int LL
#define ss second
#define v vector
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
const int N = 1e4 + 5;
v<int> f(N);
set<int> st;

struct node
{
    int res = 0;
    int count = 0;
};
map<int, node> dp[N][2][2];
node solve(string &s, int pos, bool tight, bool lead, int mask)
{

    if (pos == s.length())
    {
        node ans;
        for (int d : st)
        {
            if (((1 << d) & mask) == 0)
                return ans;
        }
        ans.count = 1;
        ans.res = 0;
        return ans;
    }
    if (dp[pos][tight][lead].count(mask))
        return dp[pos][tight][lead][mask];
    node ans;
    int start = 0;
    int end = (tight) ? s[pos] - '0' : 9;

    for (int i = start; i <= end; i++)
    {
        node cur;
        int mask_ = mask;
        if (i == 0)
        {

            if (not lead)
                mask_ |= (1 << i);
            cur = solve(s, pos + 1, tight and (i == end), lead, mask_);
        }
        else
        {
            mask_ |= (1 << i);
            cur = solve(s, pos + 1, tight and (i == end), false, mask_);
        }
        if (cur.count > 0)
        {
            ans.res = (ans.res + cur.res + (cur.count * i * f[pos])) % mod;
            ans.count = (ans.count + cur.count) % mod;
        }
    }
    return dp[pos][tight][lead][mask] = ans;
}

void solve()
{

    string s;
    cin >> s;

    int x = 1;
    int n = s.length();
    while (n > 0)
    {
        f[n - 1] = x;
        x = (x * 10) % mod;
        n--;
    }
    cin >> n;
    while (n--)
    {
        cin >> x;
        st.insert(x);
    }
    auto ans = solve(s, 0, true, true, 0);
    cout << ans.res << endl;
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