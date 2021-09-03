

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

struct node
{
    string s = "";
    int v = 0;
};

node dp[101][3];

node solve(string &s, int n, int prev)
{

    if (n == 0)
    {
        node x;
        return x;
    }

    if (dp[n][prev].v != -1)
        return dp[n][prev];

        
    if (s[n - 1] == '?')
    {

        node ans1 = solve(s, n - 1, 0);
        node ans2 = solve(s, n - 1, 1);

        ans1.s += 'B';
        ans2.s += 'R';

        ans1.v += prev == 0;
        ans2.v += prev == 1;
        
        if (ans1.v <= ans2.v)
            return dp[n][prev] = ans1;
        else
            return dp[n][prev] = ans2;
    }
    else
    {
        int cur = 0;

        if (s[n - 1] == 'R')
            cur++;
        node ans = solve(s, n - 1, cur);

        ans.v += (prev == cur);
        ans.s += s[n - 1];

        return dp[n][prev] = ans;
    }
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 3; j++)
            dp[i][j].v = -1;

    node ans = solve(s, n, 2);

    cout << ans.s << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //