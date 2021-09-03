

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

int dp[12][2][2][11];
int F[10] = {0};

string ans = "";
int k;


// 177890
//  k = 2
// pos = 0
//  tight = true
//  lead = true
//  used = 0
//  _ _ _ _ _ _ _
bool solve(string &s, int pos, bool tight, bool lead, int used)
{

    if (used > k)
        return false;

    if (pos == s.length())
    {
        return used <= k;
    }

    if (dp[pos][tight][lead][used] != -1)
        return dp[pos][tight][lead][used];

    for (int i = 0; i <= 9; i++)
    {

        if (i == 0 and lead)
            continue;

        if (tight and i >= (s[pos] - '0'))
        {

            ans += (char)(i + '0');
            bool x = true;
            if (i > s[pos] - '0')
                x = false;

            F[i]++;

            bool f = solve(s, pos + 1, x, false, used + (F[i] == 1));

            if (f)
                return dp[pos][tight][lead][used] = true;
            else
                ans.pop_back(), F[i]--;
        }
        else if (!tight)
        {

            F[i]++;

            ans += (char)(i + '0');
            bool f = solve(s, pos + 1, false, false, used + (F[i] == 1));
            if (f)
                return dp[pos][tight][lead][used] = true;
            else
                ans.pop_back(), F[i]--;
        }
    }
    return dp[pos][tight][lead][used] = false;
}

string f(int n)
{
    string x = "1023456789";

    x = x.substr(0, k);

    if (k == 1)
    {

        while (x.length() <= n)
            x += '1';

        return x;
    }

    string y = "";
    while (x.length() + y.length() <= n)
        y += '0';

    return x.substr(0, 2) + y + x.substr(2);
}

void solve()
{
    string s;

    cin >> s >> k;

    ans = "";

    for (int i = 0; i <= s.length(); i++)
        for (int j = 0; j <= 10; j++)
            dp[i][0][0][j] = dp[i][0][1][j] = dp[i][1][0][j] = dp[i][1][1][j] = -1;

    for (int i = 0; i < 10; i++)
        F[i] = 0;

    solve(s, 0, true, true, 0);

    if (ans == "")
        ans = f(s.length());

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