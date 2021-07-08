

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

int dp[200001][101];
int m;
int solve(v(int) & A, int pos, int prev)
{

    if (pos == (int)A.size())
        return 1;

    if (dp[pos][prev] != -1)
        return dp[pos][prev];

    if (A[pos] == 0)
    {
        int ans = 0;
        if (prev == 0)
        {
            for (int i = 1; i <= m; i++)
                ans = (ans + solve(A, pos + 1, i)) % mod;
        }
        else
        {

            ans = (ans + solve(A, pos + 1, prev)) % mod;
            if (prev - 1 >= 1)
                ans = (ans + solve(A, pos + 1, prev - 1)) % mod;
            if (prev + 1 <= m)
                ans = (ans + solve(A, pos + 1, prev + 1)) % mod;
        }
        return dp[pos][prev] = ans;
    }
    else
    {
        if (prev != 0 and abs(prev - A[pos]) > 1)
            return 0;

        return dp[pos][prev] = solve(A, pos + 1, A[pos]);
    }
}

void solve()
{
    int n;
    cin >> n >> m;

    v(int) A(n);
    for (int &x : A)
        cin >> x;
    memset(dp, -1, sizeof(dp));
    int ans = solve(A, 0, 0); //0 means there is no prev

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