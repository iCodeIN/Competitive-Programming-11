

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
map<int, int> dp[20][2][2];
int solve(string &s, int pos, bool tight, bool lead, int cp, const int &p)
{

    if (pos == s.length())
        return cp <= p;

    if (dp[pos][tight][lead].count(cp) > 0)
        return dp[pos][tight][lead][cp];

    int lb = 0;
    int ub = (tight) ? s[pos] - '0' : 9;

    int ans = 0;

    if (lead)
    {
        ans += solve(s, pos + 1, ub == 0, true, -1, p);

        cp = 1;
    }
    else
    {
        ans += solve(s, pos + 1, ub == 0, false, 0, p);
    }

    for (int i = lb + 1; i < ub; i++)
    {
        ans += solve(s, pos + 1, false, false, cp * i, p);
    }

    if (ub != 0)
        ans += solve(s, pos + 1, tight, lead and (ub == 0), (lead and ub == 0) ? 1 : cp * ub, p);

    return dp[pos][tight][lead][cp] = ans;
}

void solve()
{
    string s;
    cin >> s;

    int p;
    cin >> p;

    int ans = solve(s, 0, true, true, -1, p);
    // string, pos, tight, lead, product
    //    18    2      2    9^17
    cout << ans - 1 << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //