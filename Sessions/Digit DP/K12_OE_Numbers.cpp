// https://www.spoj.com/problems/KOPC12H/

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

int dp[11][2][82][73];

int solve(string &s, int pos, bool tight, int Oddsum, int evenSum)
{
    if (pos == s.length())
    {
        return evenSum > Oddsum;
    }
    int &ans = dp[pos][tight][Oddsum][evenSum];

    if (ans != -1)
        return ans;

    ans = 0;

    int start = 0;
    int end = (tight) ? s[pos] - '0' : 9;
    for (int i = start; i < end; i++)
    {
        if (i & 1)
            ans += solve(s, pos + 1, false, Oddsum + i, evenSum);
        else
            ans += solve(s, pos + 1, false, Oddsum, evenSum + i);
    }
    if (end & 1)
        ans += solve(s, pos + 1, tight, Oddsum + end, evenSum);
    else
        ans += solve(s, pos + 1, tight, Oddsum, evenSum + end);
    return ans;
}

int32_t main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;

        string l_ = to_string(l - 1);
        string r_ = to_string(r);
        memset(dp, -1, sizeof(dp));
        int ans1 = solve(r_, 0, true, 0, 0);
        memset(dp, -1, sizeof(dp));
        int ans2 = solve(l_, 0, true, 0, 0);

        cout << ans1 - ans2 << endl;
    }
    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //