
//------------------------------------------------------------------------------
#include <iostream>
#include <cstring>
#include <vector>
// #include <bits/stdc++.h>
// #include <cmath>
// #include <algorithm>
// #include <unordered_map>
// #include <map>
// #include <set>
// #include <unordered_set>
//------------------------------------------------------------------------------
using namespace std;
//------------------------------------------------------------------------------
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define v(Type) vector<Type>
#define w(T)  \
    int T;    \
    cin >> T; \
    while (T--)
#define int long long int
#define mod 1000000007ll
#define endl "\n"
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
int dp[52][2][18][18][18];

int g(string &s, int pos = 0, bool tight = 1, int c3 = 0, int c6 = 0, int c9 = 0)
{
    int len = s.length();
    if (3 * c3 > len or 3 * c6 > len or 3 * c9 > len)
        return 0;

    if (pos == len)
        return c3 >= 1 and c3 == c6 and c6 == c9;

    if (dp[pos][tight][c3][c6][c9] != -1)
        return dp[pos][tight][c3][c6][c9];

    int e = (tight) ? s[pos] - '0' : 9;
    int ans = 0;

    for (int i = 0; i < e; i++, ans %= mod)
    {
        if (i == 3)
            ans += g(s, pos + 1, false, c3 + 1, c6, c9);
        else if (i == 6)
            ans += g(s, pos + 1, false, c3, c6 + 1, c9);
        else
            ans += g(s, pos + 1, false, c3, c6, c9);
    }

    if (e == 3)
        ans += g(s, pos + 1, tight, c3 + 1, c6, c9);
    else if (e == 6)
        ans += g(s, pos + 1, tight, c3, c6 + 1, c9);
    else if (e == 9)
        ans += g(s, pos + 1, tight, c3, c6, c9 + 1);
    else
        ans += g(s, pos + 1, tight, c3, c6, c9);

    ans %= mod;

    return dp[pos][tight][c3][c6][c9] = ans;
}

int f(string &n)
{
    int k = n.length();

    for (int i = 0; i <= k; i++)
        for (int j = 0; j < 2; j++)
            for (int c1 = 0; 3 * c1 <= k; c1++)
                for (int c2 = 0; 3 * c2 <= k; c2++)
                    for (int c3 = 0; 3 * c3 <= k; c3++)
                        dp[i][j][c1][c2][c3] = -1;
    int ans = g(n);
    return ans;
}

bool check(string &s)
{
    int arr[4] = {0};

    for (int i = 0; i < s.length(); i++)
        if ((s[i] - '0') % 3 == 0)
            arr[(s[i] - '0') / 3]++;

    return arr[1] >= 1 and arr[1] == arr[2] and arr[2] == arr[3];
}
void solve()
{
    string l, r;
    cin >> l >> r;

    int R = (f(r) + check(l)) % mod;
    int L = f(l);

    int ans = (R - L + mod) % mod;

    cout << ans << endl;
}
//------------------------------------------------------------------------------
int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}
//------------------------------------------------------------------------------
