

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
#define mod 998244353ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

int dp[501][501];

int solve(int pos, int Max, int used, int n, string temp = "")
{
    if (pos == n)
    {
        if (used >= 2)
        {
            cout << temp << endl;
        }
        return used >= 2;
    }

    int start = 1;
    int end = Max;

    int &ans = dp[pos][used];

    // if (ans != -1)
    //     return ans;

    ans = 0;
    for (int i = start; i <= end; i++)
    {
        int newUsed = (i == end) ? used + 1 : used;
        ans = (ans + solve(pos + 1, Max, newUsed, n, temp + to_string(i) + " ")) % mod;
    }
    return ans;
}

void solve()
{
    int n, x;
    cin >> n >> x;

    int ans = 0;

    for (int i = 1; i <= x; i++)
    {
        memset(dp, -1, sizeof(dp));
        ans = (solve(0, i, 0, n) + ans) % mod;
        cout << ans << endl;
    }
}

int32_t main()
{

    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //