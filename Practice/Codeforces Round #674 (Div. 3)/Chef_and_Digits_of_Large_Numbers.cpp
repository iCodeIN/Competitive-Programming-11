

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
#include <unordered_map>
// #include <unordered_set>
#include <vector>

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

using namespace std;

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#define w(T)  \
    int T;    \
    cin >> T; \
    while (T--)

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define v(Type) vector<Type>
#define all(x) x.begin(), x.end()

#define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

static int fact[23];
static unordered_map<int, int> dp[23][2];

int pow(int x, int n)
{

    int ans = 1;

    while (n)
    {

        if (n & 1)
            ans *= x;
        x *= x;
        n >>= 1;
    }

    return ans;
}

int solve(string &s, int pos, int len, bool tight, int p)
{

    if (pos == len)
        return p >= fact[len];

    int P = max(p, 1ll);

    if (dp[pos][tight].count(p) > 0)
        return dp[pos][tight][p];

    int ub = (tight) ? s[pos] - '0' : 9;

    int ans = 0;
    for (int i = ub; i >= 1; i--)
    {
        int cur = solve(s, pos + 1, len, tight and i == ub, P * i);
        if ((i < ub or !tight) and cur == 0)
            break;
        ans += cur;
    }

    return dp[pos][tight][p] = ans;
}
static int DP[23];
void solve()
{
    string s;

    cin >> s;
    int ub = min(20ll, (int)s.length());

    int ans = 0;
    for (int i = 1; i < ub; i++)
        ans += DP[i];

    if (ub == s.length())
    {
        for (int i = 0; i <= ub; i++)
            dp[i][0].clear(), dp[i][1].clear();

        ans += solve(s, 0, ub, true, -1);
    }
    else
        ans += DP[ub];

    cout << ans << endl;
}

int32_t main()
{
    FastIO;
    fact[0] = 1;
    for (int i = 1; i <= 20; i++)
        fact[i] = fact[i - 1] * i;
    string s = "";
    for (int i = 1; i <= 20; i++)
    {
        DP[i] = solve(s, 0, i, false, -1);
        for (int j = 0; j < i; j++)
            dp[j][0].clear(), dp[j][1].clear();
    }
    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
