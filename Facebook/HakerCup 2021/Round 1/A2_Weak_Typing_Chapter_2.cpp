

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

int f(v(int) & dp, int prev, int i)
{
    if (prev == -1)
        return 0;

    return (prev + 1 + dp[prev]) % mod;
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    v(int) dp(n);

    int prev_x = -1;
    int prev_o = -1;

    for (int i = 0; i < n; i++)
    {
        switch (s[i])
        {

        case 'X':
            dp[i] = f(dp, prev_o, i);
            prev_x = i;
            break;
        case 'O':
            dp[i] = f(dp, prev_x, i);
            prev_o = i;
            break;
        case 'F':
            dp[i] = (i > 0) ? dp[i - 1] : 0;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
        ans = (ans + dp[i]) % mod;

    cout << ans << endl;
}
int32_t main()
{
    FastIO;
    int t = 0;
    w(T)
    {
        cout << "Case #" << ++t << ": ";
        solve();
    }
    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //