

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

const int N = 5000;

int dp[N + 1][N + 1];

int solve(string &a, string &b, int pos1, int pos2)
{
    int m = a.length();
    int n = b.length();

    if (dp[pos1][pos2] != -1)
        return dp[pos1][pos2];

    if (pos1 == m)
        return n - pos2;
    else if (pos2 == n)
        return m - pos1;

    if (a[pos1] == b[pos2])
        return solve(a, b, pos1 + 1, pos2 + 1);

    int ans1 = solve(a, b, pos1 + 1, pos2);
    int ans2 = solve(a, b, pos1, pos2 + 1);
    int ans3 = solve(a, b, pos1 + 1, pos2 + 1);

    return dp[pos1][pos2] = 1 + min({ans1, ans2, ans3});
}

void solve()
{
    string a, b;
    cin >> a >> b;

    memset(dp, -1, sizeof(dp));
    int ans1 = solve(a, b, 0, 0);
    memset(dp, -1, sizeof(dp));
    int ans2 = solve(b, a, 0, 0);

    cout << min(ans1, ans2) << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //