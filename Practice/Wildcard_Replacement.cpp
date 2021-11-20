

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
#include <stack>
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

void solve(int start, int end, string &s, v(int) & dpMin, v(int) & dpMax)
{

    if (start == end)
    {
        dpMax[start] = 1;
        dpMin[start] = 0;
    }
    else
    {
        solve(start + 3, end - 1, s, dpMin, dpMax);

        if (s[start + 2] == '+')
        {
            dpMax[start] = 1 + dpMax[start + 3];
            dpMin[start] = 0 + dpMin[start + 3];
        }
        else
        {
            dpMax[start] = 1 - dpMin[start + 3];
            dpMin[start] = 0 - dpMax[start + 3];
        }
    }
}

void solve()
{
    string s;
    cin >> s;

    int q;
    cin >> q;

    v(int) dpMin(s.length(), INT_FAST32_MAX);
    v(int) dpMax(s.length(), INT_FAST32_MAX);

    solve(0, (int)s.length() - 1, s, dpMin, dpMax);

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        --l, --r;
        int ans = dpMax[l];

        if (l == r)
            ans = 1;
        if (ans == INT32_MAX)
            cout << dpMax[-1] << endl;

        cout << ans << " ";
    }
    cout << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //