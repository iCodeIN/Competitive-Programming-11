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

// #define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

int dp[2][3][2][1000010];
int solve(v(int) & A, int K)
{

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l <= K; l++)
                    dp[i][j][k][l] = INT32_MAX;

    for (int n = 0; n <= A.size(); n++)
    {
        for (int left = 0; left <= 2; left++)
        {
            for (int started = 1; started >= 0; started--)
            {
                for (int k = 0; k <= K; k++)
                {
                    int &ans = dp[n & 1][left][started][k];

                    if (n == 0)
                    {
                        if (k == 0)
                            ans = 0;
                        else
                            ans = INT32_MAX;
                    }
                    else
                    {

                        ans = dp[(n - 1) & 1][left][false][k];

                        if (A[n - 1] <= k)
                        {
                            int ans2 = INT32_MAX;

                            if (started)
                            {
                                ans2 = dp[(n - 1) & 1][left][true][k - A[n - 1]];
                            }
                            else if (left)
                            {
                                ans2 = dp[(n - 1) & 1][left - 1][true][k - A[n - 1]];
                            }

                            if (ans2 != INT32_MAX)
                                ans2++;

                            ans = min(ans, ans2);
                        }
                    }
                }
            }
        }
    }

    return dp[A.size() & 1][2][0][K];
}

void solve()
{
    int n, k;
    cin >> n >> k;

    v(int) A(n);

    for (int &x : A)
        cin >> x;

    int ans = solve(A, k);
    if (ans == INT32_MAX)
        ans = -1;
    cout << ans << endl;
}

int32_t main()
{
    FastIO;
    int test = 1;
    w(T)
    {
        cout << "Case #" << test++ << ": ";
        solve();
    }
    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //