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

v(int) A;
int bs(int l, int r, int n)
{

    while (r - l > 1)
    {
        int m = (l + r) / 2;

        if (((m) * (m + 1)) / 2 >= n)
            r = m;
        else
            l = m;
    }
    return r;
}

int isGood(int x, int n)
{
    int l = 0;
    int r = n;

    while (l <= r)
    {
        int m = (l + r) / 2;
        if ((m) * (m + 1) == 2 * x)
            return m;
        else if ((m) * (m + 1) <= 2 * x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
void solve()
{
    int n;
    cin >> n;
    int ans = 0;

    int start = bs(-1, n + 1, n);
    cout << endl;
    for (int i = n; i >= start;)
    {
        int cur = (i + 1) * (i);
        cur >>= 1ll;
        if (isGood(cur - n, n) != -1)
        {
            ans++;
            cout << i << " " << isGood(cur - n, n) << endl;
            // ++i;
            // i >>= 1;
        }
        // else
            i--;
    }
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