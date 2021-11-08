

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
#define mod 100000000ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

int dp[101][101][4];

int solve(int N1, int N2, int k1, int k2)
{

    for (int n1 = 0; n1 <= N1; n1++)
    {
        for (int n2 = 0; n2 <= N2; n2++)
        {
            for (int place = 1; place <= 3; place++)
            {
                int &ans = dp[n1][n2][place];
                if (n1 == 0)
                {
                    ans = place != 1 and n2 <= k2;
                }
                else if (n2 == 0)
                {
                    ans = place != 2 and n1 <= k1;
                }
                else
                {
                    ans = 0;
                    if (place != 2)
                    {
                        for (int i = 1; i <= min(n1, k1); i++)
                            ans = (ans + dp[n1 - i][n2][2]) % mod;
                    }

                    if (place != 1)
                    {
                        for (int i = 1; i <= min(n2, k2); i++)
                            ans = (ans + dp[n1][n2 - i][1]) % mod;
                    }
                }
            }
        }
    }
    return dp[N1][N2][3];
}

void solve()
{
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    int ans = solve(n1, n2, k1, k2);

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