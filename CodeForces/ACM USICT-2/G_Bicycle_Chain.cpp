

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

#define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

void solve()
{
    int mxIntegerRatio = -1;

    int n;
    cin >> n;
    v(int) A(n);
    for (int &x : A)
        cin >> x;

    int m;
    cin >> m;
    v(int) B(m);
    for (int &x : B)
        cin >> x;
    int ans = 0;
    for (int &x : A)
        for (int &y : B)
            if (y % x == 0)
                mxIntegerRatio = max(y / x, mxIntegerRatio);

    for (int &x : A)
        for (int &y : B)
            if (y % x == 0)
                ans += ((y / x) == mxIntegerRatio);

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