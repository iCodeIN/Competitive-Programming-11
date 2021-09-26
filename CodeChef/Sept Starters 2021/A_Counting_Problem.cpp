

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
#include <bits/stdc++.h>
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
    cin.tie(NULL);                   

#define v(Type) vector<Type>
#define all(x) x.begin(), x.end()

#define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#define f(x) max(100000 - (x) + 1, 0ll)

v(int) A, Minpossible;

int dp[100001][2][2];

int solve(int n, bool rightAvl, bool satisfied)
{

    if (n == 0)
        return (rightAvl) ? f(Minpossible[0]) : 1;

    int &f_ans = dp[n][rightAvl][satisfied];

    if (f_ans != -1)
        return f_ans;
        
    int ans = 0;

    if ((rightAvl and Minpossible[n] == A[n - 1]) or satisfied)
    {
        int ans1 = solve(n - 1, true, false);
        ans += ans1;
    }

    if (Minpossible[n - 1] == A[n - 1])
    {
        int ans2 = solve(n - 1, false, n >= 2 and A[n - 1] == A[n - 2]);

        int rightOptions = 1;

        if (rightAvl)
        {
            if (Minpossible[n] == A[n - 1])
                rightOptions = f(Minpossible[n] + 1);
            else
                rightOptions = f(Minpossible[n]);
        }

        ans2 = (ans2 * rightOptions) % mod;

        ans = (ans + ans2) % mod;
    }

    return f_ans = ans;
}

void solve()
{
    int n;
    cin >> n;

    n--;

    A.assign(n, 0);
    for (int &x : A)
        cin >> x;

    Minpossible.assign(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        Minpossible[i] = max(Minpossible[i], A[i]);
        Minpossible[i + 1] = max(Minpossible[i + 1], A[i]);
    }

    memset(dp, -1, sizeof(dp));

    int ans = solve(n, true, false);

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
