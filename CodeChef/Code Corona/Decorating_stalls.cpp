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
bool good(int x, int a, int b, int c)
{
    if (a < x)
        return false;

    int firstRow = x;
    a -= x;
    int secondRow = min(x, a);
    a -= secondRow;
    int req = x - secondRow;
    if (req > 0)
    {
        int temp = min(req, b);
        secondRow += temp;
        req -= temp;
        b -= temp;
    }
    if (req > 0)
    {
        int temp = min(req, c);
        secondRow += temp;
        req -= temp;
        c -= temp;
    }

    return firstRow == x and secondRow == x and b + c >= x;
}

int solve(int a, int b, int c)
{
    int l = 0;
    int r = 1e9;
    r *= 10;

    while (r - l > 1)
    {
        int m = (l + r) >> 1;

        if (good(m, a, b, c))
            l = m;
        else
            r = m;
    }
    return l;
}

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    int M = max({a, b, c});
    int m = min({a, b, c});
    int mid = a ^ b ^ c ^ M ^ m;
    int ans = solve(M, mid, m);
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