

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

int solve(v(string) & A, int x, int y, v(v(int)) & dp)
{
    int m = A.size();
    int n = A[0].size();

    if (x >= m or y >= n or A[x][y] == '#')
        return 0;

    if (x == m - 1 and y == n - 1)
        return 1;

    if (dp[x][y] != -1)
        return dp[x][y];

    int ans1 = solve(A, x, y + 1, dp);
    int ans2 = solve(A, x + 1, y, dp);

    return dp[x][y] = (ans1 + ans2) % mod;
}

void solve()
{
    int m, n;
    cin >> m >> n;

    v(string) A(m);
    for (int i = 0; i < m; i++)
        cin >> A[i];

    v(v(int)) dp(m, v(int)(n, -1));

    int ans = solve(A, 0, 0, dp);

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