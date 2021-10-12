

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

int A[100000];

int bs(int x)
{
    // leftmost val >= x

    int l = 0;
    int r = 61;

    while (r - l > 1)
    {
        int m = (l + r) >> 1ll;

        int val = (1ll << m) - 1ll;

        if (val >= x)
            r = m;
        else
            l = m;
    }
    return (1ll << r) - 1;
}

void solve(int n, int &idx)
{
    if (n == 0)
        return;

    int x = bs(n);

    A[++idx] = x;
    solve(n ^ x, idx);
}

void solve()
{
    int n;
    cin >> n;

    int idx = -1;
    solve(n, idx);

    if (idx == -1)
    {
        A[++idx] = 1;
        A[++idx] = 1;
    }

    cout << idx + 1 << endl;
    for (int i = 0; i <= idx; i++)
        cout << A[i] << " ";
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