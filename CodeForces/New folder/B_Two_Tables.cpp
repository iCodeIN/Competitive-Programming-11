

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

void solve()
{
    int h, w;
    cin >> w >> h;

    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    int H, W;
    cin >> W >> H;

    int ans = INT32_MAX;

    if (W + (x2 - x1) <= w)
    {
        if (W < x1)
            ans = 0;
        else
            ans = min(ans, W - x1);

        if (W < w - x2)
            ans = 0;
        else
            ans = min(ans, W - (w - x2));
    }

    if (H + (y2 - y1) <= h)
    {
        if (H < h - y2)
            ans = 0;
        else
            ans = min(ans, H - (h - y2));
        if (H < y1)
            ans = 0;
        else
            ans = min(ans, H - y1);
    }

    if (ans == INT32_MAX)
        ans = -1;

    cout << setprecision(6) << ans << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //