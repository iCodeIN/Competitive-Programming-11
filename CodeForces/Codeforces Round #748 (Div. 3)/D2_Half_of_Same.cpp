

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

int dp[41][41][21];

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int solve(v(int) & A, int n, int prev, int choosen)
{

    if (2 * choosen == A.size())
    {
        return 0; // all good
    }

    if (n == 0)
    {
        return INT32_MIN; // invalid
    }

    int ans1 = solve(A, n - 1, prev, choosen); // not choosing
    int ans2 = solve(A, n - 1, n - 1, choosen + 1);


    if (ans2 != INT32_MIN)
    {
        if (A[prev] != A[n - 1])
            ans2 = gcd(ans2, A[prev] - A[n - 1]);
    }

    
    return max(ans1, ans2);
}

bool check(v(int) & A)
{
    int n = A.size();
    for (int i = 0; i < A.size();)
    {
        int j = i;
        int c = 0;
        while (j < n and A[j] == A[i])
            j++, c++;

        i = j;

        if (c >= n / 2)
            return true;
    }
    return false;
}
void solve()
{
    int n;
    cin >> n;

    v(int) A(n);

    for (int &x : A)
        cin >> x;

    sort(all(A));

    A.push_back(A[n - 1]);

    int ans = solve(A, A.size(), n, 0);
    memset(dp, -1, sizeof(dp));
    if (check(A))
        ans = -1;
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