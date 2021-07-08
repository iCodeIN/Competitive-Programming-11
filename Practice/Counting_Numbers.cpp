

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
#include <bits/stdc++.h>
// #include <cmath>
// #include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>
// #include <vector>

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
int dp[22][2][11][2];
int f(string &s, int pos = 0, bool tight = true, int prev = 10, bool lead = true)
{
    if (pos == (int)s.length())
    {
        return 1;
    }
    if (dp[pos][tight][prev][lead] != -1)
        return dp[pos][tight][prev][lead];
    int lb = 0;
    int ub = (tight) ? (s[pos] - '0') : 9;
    int ans = 0;
    for (int i = lb; i < ub; i++)
    {
        if (i != prev or lead)
            ans += f(s, pos + 1, false, i, lead and i == 0);
    }
    if (ub != prev or lead)
    {
        ans += f(s, pos + 1, tight, ub, lead and ub == 0);
    }

    return dp[pos][tight][prev][lead] = ans;
}

void solve()
{
    int l, r;
    cin >> l >> r;

    string l_ = to_string(l - 1);
    string r_ = to_string(r);

    memset(dp, -1, sizeof(dp));
    int ans = f(r_);

    if (l != 0)
    {
        memset(dp, -1, sizeof(dp));
        ans -= f(l_);
    }

    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //