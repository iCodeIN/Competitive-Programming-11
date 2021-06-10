

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
#include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// #include <unordered_map>
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

int dp[20][2][20];
int f(string &s, int pos = 0, bool tight = true, int trailing = 0)
{
    if (pos == s.length())
    {
        return trailing + 1;
    }
    if (dp[pos][tight][trailing] != -1)
        return dp[pos][tight][trailing];
    int start = 0;
    int e = (tight) ? s[pos] - '0' : 9;

    int ans = 0;
    for (int i = start; i <= e - 1; i++)
        ans += f(s, pos + 1, false, 0);
    if (e == 9)
        ans += f(s, pos + 1, tight, trailing + 1);
    else
        ans += f(s, pos + 1, tight, 0);
    return dp[pos][tight][trailing] = ans;
}

int extra(int l, int r)
{
    string l_ = to_string(l - 1);
    string r_ = to_string(r - 1);
    memset(dp, -1, sizeof(dp));
    int ans = f(r_);
    // cout << f(r_) << " ";
    memset(dp, -1, sizeof(dp));
    ans -= f(l_);

    // cout << f(l_) << " ";
    return ans;
}

void solve()
{
    int l, r;
    cin >> l >> r;

    // int ans = r - l;

    int x = extra(l, r);

    cout << x << "\n";
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //