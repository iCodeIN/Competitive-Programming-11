

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

int solve(int x, int l, int r, int sm, int lg, int pos)
{
    int ans = 1;
    while (l < r)
    {
        int m = (l + r) >> 1;

        if (m < pos) // choti value
        {
            ans = (ans * sm) % mod;
            sm--;
            l = m + 1;
        }
        else if (m == pos)
        {
            l = m + 1;
        }
        else
        {
            ans = (ans * lg) % mod;
            lg--;
            r = m;
        }
    }

    int rem = sm + lg;

    for (int i = 1; i <= rem; i++)
    {
        ans = (ans * i) % mod;
    }
    return ans;
}
void solve()
{
    int n, x, pos;
    cin >> n >> x >> pos;

    int l = 0;
    int r = n;

    int ans = solve(x, l, r, x - 1, n - x, pos);

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