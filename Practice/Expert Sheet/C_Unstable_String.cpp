

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

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    v(v(int)) dp(n, v(int)(2));

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {

            switch (s[i])
            {
            case '0':
                dp[i][0] = 1;
                break;
            case '1':
                dp[i][1] = 1;
                break;
            default:
                dp[i][0] = dp[i][1] = 1;
            }
        }
        else
        {
            switch (s[i])
            {
            case '0':
                dp[i][0] = max(0ll, dp[i - 1][1]) + 1;
                break;
            case '1':
                dp[i][1] = max(0ll, dp[i - 1][0]) + 1;
                break;
            default:
                dp[i][0] = max(0ll, dp[i - 1][1]) + 1;
                dp[i][1] = max(0ll, dp[i - 1][0]) + 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += max(dp[i][0], dp[i][1]);

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