

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

int solve(v(int) & A, int k, int n)
{
    int ans = INT32_MAX;

    pair<int, int> dp[n + 1][n + 2];

    for (int i = n; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            if (i == n)
                dp[i][j] = {0, 0};
            else
            {
                auto ans1 = dp[i + 1][j + 1];
                ans1.first += (A[i] == j);
                auto ans2 = dp[i + 1][j];
                ans2.second++;
                pair<int, int> ans;

                ans.first = max(ans1.first, ans2.first);

                if (ans2.first > ans1.first)
                    ans.second = ans2.second;
                else
                    ans.second = ans1.second;

                dp[i][j] = ans;
            }

            if (dp[i][j].first >= k)
                ans = min(ans, dp[i][j].second);
        }
    }
    for (int i = 0; i <= n; i++, cout << endl)
        for (int j = 0; j <= i; j++)
            cout << dp[i][j].first << ',' << dp[i][j].second << " ";
    return (ans == INT32_MAX) ? -1 : ans;
}

void solve()
{
    int n;
    int k;
    cin >> n >> k;
    // max good elements after deleting p elments

    v(int) A(n);
    for (int &x : A)
        cin >> x;

    auto ans = solve(A, k, A.size());

    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //