

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
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

int bs(v(int) & A, int l, int r, int a, int b)
{
    if (l > r or a > b)
        return 0;

    int start = l - 1;
    int end = r + 1;
    int left = 0;
    while (end - start > 1)
    {
        int m = (start + end) >> 1;

        if (A[m] >= a)
            end = m;
        else
            start = m;
    }
    if (end == r + 1)
        return 0;
    left = end;

    start = l - 1;
    end = r + 1;
    int right = 0;
    while (end - start > 1)
    {
        int m = (start + end) >> 1;

        if (A[m] <= b)
            start = m;
        else
            end = m;
    }

    if (start == l - 1)
        return 0;
    right = start;

    if (right < left)
        return 0;
    return right - left + 1;
}

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;

    v(int) A(n);
    for (int &x : A)
        cin >> x;

    sort(all(A));

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += bs(A, 0, i - 1, l - A[i], r - A[i]) + bs(A, i + 1, n - 1, l - A[i], r - A[i]);
    }
    ans >>= 1;
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