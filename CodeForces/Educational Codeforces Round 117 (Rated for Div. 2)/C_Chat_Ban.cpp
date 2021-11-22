

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

int sum(int n)
{
    if (n & 1)
        return ((n + 1) / 2) * n;
    return ((n) / 2) * (n + 1);
}

int sum_(int a, int t)
{
    int t1 = t;
    int t2 = (2 * a) - t + 1;

    if (t2 & 1)
        swap(t1, t2);

    return (t2 / 2) * t1;
}

void solve()
{
    int k, x;
    cin >> k >> x;

    int l = -1;
    int r = k + 1;
    int ans = 0;
    if (x <= sum(k))
    {

        while (r - l > 1)
        {
            int m = (l + r) >> 1ll;

            if (sum(m) < x)
                l = m;
            else
                r = m;
        }
        ans = r;
    }
    else
    {
        // cout << "s ";
        ans = k;
        // cout << ans << " ";
        x -= sum(k);
        if (x > 0)
        {
            l = -1;
            r = k - 1;

            while (r - l > 1)
            {

                int m = (l + r) >> 1ll;

                if (sum_(k - 1, m) < x)
                    l = m;
                else
                    r = m;
            }
            ans += r;
        }
    }

    cout << ans << "\n";
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //