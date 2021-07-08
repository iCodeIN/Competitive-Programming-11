

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
// #include <vector>

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
int memo[5001][5001];
int solve(string &a, string &b, int n1, int n2)
{

    if (n1 == 0 or n2 == 0)
    {
        return max(n1, n2);
    }
    if (memo[n1][n2] != -1)
        return memo[n1][n2];
    if (a[n1 - 1] == b[n2 - 1])
    { // both equal no need to perform any op
        return solve(a, b, n1 - 1, n2 - 1);
    }

    int ans1 = 1 + solve(a, b, n1 - 1, n2 - 1); // replace
    int ans2 = 1 + solve(a, b, n1, n2 - 1);     // add
    int ans3 = 1 + solve(a, b, n1 - 1, n2);     // remove

    return memo[n1][n2] = min(ans1, min(ans2, ans3));
}
void solve()
{
    string a, b;
    cin >> a >> b;
    memset(memo, -1, sizeof(memo));
    int ans1 = solve(a, b, a.length(), b.length()); // cost of tranforming a -> b
    swap(a, b);
    memset(memo, -1, sizeof(memo));
    int ans2 = solve(a, b, a.length(), b.length()); // cost of tranforming b -> a

    int ans = min(ans1, ans2);
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