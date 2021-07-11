// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
// #include <set>
#include <queue>
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
struct item
{
    int l;
    int r;
    int m;
    int d;
};

int count(item x)
{
    if (x.l < x.m and x.m < x.r)
    {

        item l_, r_;

        l_.l = x.l;
        l_.r = x.m;
        l_.m = (l_.l + l_.r) >> 1;
        l_.d = l_.r - l_.l;

        r_.l = x.m;
        r_.r = x.r;
        r_.m = (r_.l + r_.r) >> 1;
        r_.d = r_.r - r_.l;

        return 1 + count(l_) + count(r_);
    }
    return 0;
}
void solve()
{
    int n, c;
    cin >> n >> c;

    v(item) A(n);

    for (item &x : A)
    {
        cin >> x.l >> x.r;
        x.m = (x.l + x.r) >> 1;
        x.d = x.r - x.l;
    }
    int ans = 0;
    int rem = c;

    for (item p : A)
    {
        int cur = count(p);
        ans++;
        if (rem >= 0)
        {
            ans += min(cur, rem);
            rem -= min(cur, rem);
        }
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
