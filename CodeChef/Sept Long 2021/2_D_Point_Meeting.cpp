

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
#include <set>
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

int f(v(int) & X, v(int) & Y, int x, int y)
{

    int ans = 0;
    int n = X.size();

    for (int i = 0; i < n; i++)
    {
        int k = x - X[i];

        ans += (k != 0);
        ans += (!((Y[i] == y) or (Y[i] + k == y) or (Y[i] - k == y)));
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    v(int) X(n), Y(n);

    for (int &x : X)
        cin >> x;
    for (int &y : Y)
        cin >> y;

    set<int> x, y;

    for (auto px : X)
        x.insert(px);
    for (auto py : Y)
        y.insert(py);

    int ans = INT32_MAX;
    for (auto x_ : x)
        for (auto y_ : y)
            ans = min(ans, f(X, Y, x_, y_));

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