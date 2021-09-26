

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

int L = 0;
int R;

int dp[1010][1010];

int solve(v(int) & A, v(int) & B, int left, int right)
{
    int l_ = left;
    int r_ = R - right;

    int idx = l_ + r_;

    if (idx >= B.size())
        return 0;

    if (dp[l_][r_] != -1)
        return dp[l_][r_];

    int ans1 = (B[idx] * A[left]) + solve(A, B, left + 1, right);
    int ans2 = (B[idx] * A[right]) + solve(A, B, left, right - 1);

    return dp[l_][r_] = max(ans1, ans2);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    R = n - 1;

    v(int) A(n);
    v(int) B(m);

    for (int &x : A)
        cin >> x;
    for (int &x : B)
        cin >> x;

    memset(dp, -1, sizeof(dp));
    int ans = solve(A, B, 0, n - 1);

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