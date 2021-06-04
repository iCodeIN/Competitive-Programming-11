

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
    v(v(int)) unknown(n, v(int)(3, 0));
    v(int) dp(n, 0);
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;

        if (s[i] == '?')
        {
            if (s[i - 1] == '?')
            {
                unknown[i][0] = 2 + unknown[i - 1][1];

                unknown[i][1] = 2 + unknown[i - 1][0];
            }
            else
            {
                if (s[i - 1] == '0')
                    unknown[i][1] = 2 + unknown[i - 1][0];
                else
                    unknown[i][0] = 2 + unknown[i - 1][1];
            }
            dp[i] = max(unknown[i][0], unknown[i][1]);
        }
        else
        {
            if (s[i - 1] == '?')
            {
                if (s[i] == '0')
                    dp[i] = 1 + unknown[i - 1][1];
                else
                    dp[i] = 1 + unknown[i - 1][0];
            }
            else
            {
                if (s[i] != s[i - 1])
                    dp[i] = 1 + dp[i - 1];
            }
        }
    }

    int ans = 0;
    for (int &x : dp)
    {
        cout << x << " ";
        ans += x;
    }
    cout << endl;
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