

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
    int n2, n3, n4;
    cin >> n2 >> n3 >> n4;

    int ans = 0;

    if (n3 > 0)
    {
        int cur = min(n3 / 2, n4);

        n3 -= 2 * cur;
        n4 -= cur;

        ans += cur;
    }

    if (n4 > 0)
    {
        int cur = min(n4 / 2, n2);

        n4 -= 2 * cur;
        n2 -= cur;

        ans += cur;
    }

    if (n3 > 0)
    {

        int cur = min(n3 / 2, n2 / 2);

        n3 -= 2 * cur;
        n2 -= 2 * cur;

        ans += cur;
    }

    if (n4 > 0)
    {
        int cur = min(n2 / 3, n4);

        n2 -= 3 * cur;
        n4 -= cur;

        ans += cur;
    }

    if (n2 > 0)
    {
        int cur = n2 / 5;
        n2 -= cur * 5;
        
        ans += cur;
    }

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