

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
#include <map>
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

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return min(a, b) * (max(b, a) / gcd(a, b));
}

map<pair<int, int>, int> dp[51];

int solve(v(int) & A, v(int) & B, int n, int g1, int g2)
{
    if (n == 0)
    {
        return lcm(g1, g2);
    }

    if (dp[n].count({g1, g2}) > 0)
        return dp[n][{g1, g2}];

    int ans1 = solve(A, B, n - 1, gcd(g1, A[n - 1]), gcd(g2, B[n - 1]));
    int ans2 = solve(A, B, n - 1, gcd(g1, B[n - 1]), gcd(g2, A[n - 1]));

    return dp[n][{g1, g2}] = max(ans1, ans2);
}

void solve()
{

    int n;
    cin >> n;

    v(int) A(n), B(n);

    for (int i = 0; i < n; i++)
        cin >> A[i] >> B[i];

    int ans = solve(A, B, n - 1, A[n - 1], B[n - 1]);

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