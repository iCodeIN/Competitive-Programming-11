

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
int dp[100001][2][2];

int solve(string &s, int n, int k, int pos, bool tight, bool op)
{

    char lb = 'a';
    char ub = (tight) ? s[pos] : 'a' + k - 1;

    if (ub > 'a' + k - 1)
    {
        tight = false;
        op = false;
        ub = 'a' + k - 1;
    }

    if (pos == n / 2)
    {
        if (n & 1)
            return ub - lb + !(op);
        else
            return !(op);
    }

    // if (dp[pos][tight][op] != -1)
    //     return dp[pos][tight][op];

    int ans = 0;

    while (lb <= ub)
    {
        ans = (ans + solve(s, n, k, pos + 1, (tight) & (lb == ub), op and tight and lb >= s[n - 1 - pos])) % mod;
        ++lb;
    }
    return dp[pos][tight][op] = ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    int ans = solve(s, n, k, 0, true, true);

    cout << ans << endl;
}

int32_t main()
{
    FastIO;
    int test = 1;
    w(T)
    {
        cout << "Case #" << test++ << ": ";
        solve();
    }

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
