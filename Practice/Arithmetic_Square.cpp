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

bool check(int a, int b, int c)
{
    return b - a == c - b;
}

void possible(int a, int c, map<int, int> &mp)
{
    if ((c - a) % 2 == 0)
    {
        int b = a + ((c - a) / 2);
        mp[b]++;
    }
}

void solve()
{
    v(v(int)) A(3, v(int)(3));
    int n = 3;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == 1 and j == 1)
                continue;
            else
                cin >> A[i][j];

    map<int, int> mp;
    int ans = 0;

    ans += check(A[0][0], A[0][1], A[0][2]);
    ans += check(A[2][0], A[2][1], A[2][2]);
    ans += check(A[0][0], A[1][0], A[2][0]);
    ans += check(A[0][2], A[1][2], A[2][2]);

    // options
    possible(A[0][1], A[2][1], mp);

    possible(A[1][0], A[1][2], mp);

    possible(A[0][0], A[2][2], mp);

    possible(A[0][2], A[2][0], mp);
    // x1 x2 x3
    // x4 _ x5
    // x6 x7 x8
    int mxF = 0;
    for (auto p : mp)
    {
        mxF = max(p.second, mxF);
    }

    ans += mxF;

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