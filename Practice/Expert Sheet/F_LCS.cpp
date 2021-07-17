

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
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
int dp[3001][3001] = {0};
void f(string &x, string &y, int l1, int l2)
{
    // if (l1 == 0 or l2 == 0)
    //     return 0;

    // if (x[l1 - 1] == y[l2 - 1])
    //     return 1 + f(x, y, l1 - 1, l2 - 1);

    // int ans1 = f(x, y, l1 - 1, l2);
    // int ans2 = f(x, y, l1, l2 - 1);

    // return max(ans1, ans2);

    for (int i = 0; i <= l1; i++)
        for (int j = 0; j <= l2; j++)
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    int i = l1;
    int j = l2;

    string ans = "";
    while (i >= 1 and j >= 1)
    {
        if (dp[i - 1][j] == dp[i][j])
            i--;
        else if (dp[i][j - 1] == dp[i][j])
            j--;
        else
            ans += x[i - 1], i--, j--;
    }
    if (ans.length())
        reverse(all(ans));
    cout << ans << endl;
}

void solve()
{
    string x, y;
    cin >> x >> y;

    f(x, y, x.length(), y.length());

    // cout << ans << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //