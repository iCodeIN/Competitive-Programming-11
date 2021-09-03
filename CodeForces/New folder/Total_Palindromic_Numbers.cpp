

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

int dp[20][20][2][2][2];
int solve(string &s, int start, int end, bool first, bool tight, bool strict)
{

    if (dp[start][end][first][tight][strict] != -1)
        return dp[start][end][first][tight][strict];

    if (start == end)
    {
        int ans = 0;

        if (tight)
            ans = (s[start] - '0') + 1 - (strict) - (first);
        else
            ans = 10 - first;

        return dp[start][end][first][tight][strict] = ans;
    }

    if (end - start == 1)
    {

        int ans = 0;

        if (tight)
        {
            int f = s[start] - '0';
            int e = s[end] - '0' - strict;
            if (f <= e)
                ans = f + 1 - first;
            else
                ans = max(0ll, (f - 1) + 1 - first);
        }
        else
            ans = 10 - first;

        return dp[start][end][first][tight][strict] = ans;
    }
    int lb = (first) ? 1 : 0;
    int ub = (tight) ? s[start] - '0' : 9;

    int ans = 0;

    for (int i = lb; i < ub; i++)
        ans += solve(s, start + 1, end - 1, false, false, false);

    if (ub >= lb)
        ans += solve(s, start + 1, end - 1, false, tight, tight and ((s[start] > s[end]) or (s[start] == s[end] and strict)));

    return dp[start][end][first][tight][strict] = ans;
}

void solve()
{
    int l_, r_;
    cin >> l_ >> r_;
    
    if (l_ > r_)
        swap(l_, r_);
    
    int L = 0;
    int R = 0;

    auto r = to_string(r_);
    auto l = to_string(l_ - 1);
    
    memset(dp, -1, sizeof(dp));
    R = solve(r, 0, r.length() - 1, true, true, false);
    for (int i = 1; i < r.length(); i++)
        R += solve(r, i, r.length() - 1, true, false, false);

    memset(dp, -1, sizeof(dp));
    L = solve(l, 0, l.length() - 1, true, true, false);
    for (int i = 1; i < l.length(); i++)
        L += solve(l, i, l.length() - 1, true, false, false);

    cout << R - L << endl;
}

int32_t main()
{
    FastIO;
    int t = 0;
    w(T)
    {
        cout << "Case " << ++t << ": ";
        solve();
    }

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //F