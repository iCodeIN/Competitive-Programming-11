

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

int count(v(int) & A, int l, int r, int x)
{
    // leftmost >= x

    int end = r;

    while (r - l > 1)
    {
        int m = (l + r) >> 1;

        if (A[m] >= x)
            r = m;
        else
            l = m;
    }

    return end - r;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    v(int) A(n);

    for (int &x : A)
        cin >> x;

    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        l -= 2;
        int ans = count(A, l, r, x);
        cout << ans << endl;
    }
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //