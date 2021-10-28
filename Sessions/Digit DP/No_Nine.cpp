// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050ff4/0000000000051183

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

int dp[20][2][180];

int solve(string &s, int pos, bool tight, int sum)
{
    if (pos == s.length())
    {
        return sum % 9 != 0;
    }
    int &ans = dp[pos][tight][sum];

    if (ans != -1)
        return ans;

    ans = 0;

    int start = 0;
    int end = (tight) ? s[pos] - '0' : 9;
    for (int i = start; i < end; i++)
    {
        if (i == 9)
            continue;
        ans += solve(s, pos + 1, false, sum + i);
    }
    if (end != 9)
        ans += solve(s, pos + 1, tight, sum + end);
    return ans;
}

int32_t main()
{
    FastIO;
    int t;
    cin >> t;
    int i = 1;
    while (i <= t)
    {
        int l, r;
        cin >> l >> r;

        if (l == -1 and r == -1)
            break;
        string l_ = to_string(l - 1);
        string r_ = to_string(r);
        memset(dp, -1, sizeof(dp));
        int ans1 = solve(r_, 0, true, 0);
        memset(dp, -1, sizeof(dp));
        int ans2 = solve(l_, 0, true, 0);
        cout << "Case #" << i++ << ": ";
        cout << ans1 - ans2 << endl;
    }
    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //