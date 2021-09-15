

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
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define v(Type) vector<Type>
#define all(x) x.begin(), x.end()

#define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
const int N = 2 * 1e5 + 10;

int dp[N + 1];

struct node
{

    int s;
    int e;
    int v;

    bool operator<(node b)
    {
        auto a = *this;
        
        return a.s < b.s;
    }
};

int justGreater(v(node) & A, int l, int x)
{

    // leftmost > x

    int r = A.size();

    while (r - l > 1)
    {
        int m = (l + r) >> 1;

        if (A[m].s > x)
            r = m;
        else
            l = m;
    }

    return r;
}

int solve(v(node) & A, int pos)
{
    int n = A.size();
    if (pos == n)
        return 0;

    if (dp[pos] != -1)
        return dp[pos];

    int ans1 = solve(A, pos + 1);

    int nextPos = justGreater(A, pos, A[pos].e);

    int ans2 = A[pos].v + solve(A, nextPos);

    return dp[pos] = max(ans1, ans2);
}

void solve()
{
    int n;
    cin >> n;

    v(node) A(n);

    for (auto &x : A)
        cin >> x.s >> x.e >> x.v;

    sort(A.begin(), A.end());


    memset(dp, -1, sizeof(dp));

    int ans = solve(A, 0);

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