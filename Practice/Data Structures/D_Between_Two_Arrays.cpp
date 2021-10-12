

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

static int dp[3001][3001];

int solve(v(int) & A, v(int) & B, int pos, int prev)
{

    int n = A.size();
    if (pos >= n)
        return 1;
    int &ans = dp[pos][prev];

    if (ans != -1)
        return ans;

    ans = 0;

    for (int i = max(prev, A[pos]); i <= B[pos]; i++)
        ans = (ans + solve(A, B, pos + 1, i)) % mod;

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    v(int) A(n);
    v(int) B(n);

    for (int &x : A)
        cin >> x;
    for (int &x : B)
        cin >> x;

    memset(dp, -1, sizeof(dp));

    // cout << "all well";

    int ans = solve(A, B, 0, 0);

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