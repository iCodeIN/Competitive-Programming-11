

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

int memo[100001][3][105];

int f(string &s, int &d, int pos = 0, bool tight = true, int sum = 0)
{

    if (pos == (int)s.length())
        return sum == 0;

    if (memo[pos][tight][sum] != -1)
        return memo[pos][tight][sum];

    int ul = (tight) ? s[pos] - '0' : 9;
    int ans = 0;

    for (int i = 0; i < ul; i++)
        ans = (ans + f(s, d, pos + 1, false, (sum + i) % d)) % mod;

    ans = (ans + f(s, d, pos + 1, tight, (sum + ul) % d)) % mod;

    return memo[pos][tight][sum] = ans;
}

void solve()
{
    string s;
    cin >> s;

    int d;
    cin >> d;

    memset(memo, -1, sizeof(memo));

    int ans = f(s, d) - 1;
    ans = (ans + mod) % mod;

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