

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
#include <bits/stdc++.h>
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
#define mod 998244353ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

int dp[1001][2][2][2][2][2][2][2][2][2][2][12];

int solve(string &s, int pos, bool A, bool B, bool C, bool D, bool E, bool F, bool G, bool H, bool I, bool J, char prev)
{

    if (pos == s.length())
        return 1;

    if (dp[pos][A][B][C][D][E][F][G][H][I][J][prev - 'A' + 1] != -1)
        return dp[pos][A][B][C][D][E][F][G][H][I][J][prev - 'A' + 1];

    int ans1 = solve(s, pos + 1, A, B, C, D, E, F, G, H, I, J, prev);
    int ans2 = 0;

    char ch = s[pos];
    bool *temp = &A;

    if (ch == 'A')
        temp = &A;

    else if (ch == 'B')
        temp = &B;
    else if (ch == 'C')
        temp = &C;
    else if (ch == 'D')
        temp = &D;
    else if (ch == 'E')
        temp = &E;
    else if (ch == 'F')
        temp = &F;
    else if (ch == 'G')
        temp = &G;
    else if (ch == 'H')
        temp = &H;
    else if (ch == 'I')
        temp = &I;
    else if (ch == 'J')
        temp = &J;

    if ((*temp) == false)
    {
        *temp = true;
        ans2 = solve(s, pos + 1, A, B, C, D, E, F, G, H, I, J, ch);
        *temp = false;
    }
    else if (temp and prev == ch)
    {
        ans2 = solve(s, pos + 1, A, B, C, D, E, F, G, H, I, J, ch);
    }

    return dp[pos][A][B][C][D][E][F][G][H][I][J][(prev - 'A') + 1] = (ans1 + ans2) % mod;
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    memset(dp, -1, sizeof(dp));

    int ans = solve(s, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'A' - 1);
    ans = (ans - 1 + mod) % mod;
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