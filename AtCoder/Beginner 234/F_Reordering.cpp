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
int mp[26] = {0};
int fact[5002];
int dp[26][5001];
int modInv(int x)
{
    int n = mod - 2;
    int ans = 1;
    while (n)
    {
        if (n & 1)
        {
            ans = (ans * x) % mod;
        }

        n /= 2;
        x = (x * x) % mod;
    }
    return ans;
}

int solve(int pos, int choosen)
{
    if (pos == 26)
        return fact[choosen];
    int &ans = dp[pos][choosen];
    if (ans != -1)
        return ans;
    ans = 0;
    for (int i = 0; i <= mp[pos]; i++)
    {
        int num = solve(pos + 1, choosen + i);
        int denInv = modInv(fact[i]);
        ans = (ans + (num * denInv) % mod) % mod;
    }
    return ans;
}
void solve()
{
    fact[0] = 1;
    for (int i = 1; i <= 5000; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    memset(dp, -1, sizeof(dp));
    string s;
    cin >> s;
    for (char ch : s)
        mp[ch - 'a']++;
    int ans = solve(0, 0);
    ans--;
    ans = (ans + mod) % mod;
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