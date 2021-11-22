

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

bool good(v(int) & A, int x, int c)
{
    int count = 1;
    int prev = A[0];
    int n = A.size();
    for (int i = 1; i < n; i++)
    {
        int cur = A[i];
        if (cur - prev >= x)
            count++, prev = cur;
    }
    return count >= c;
}

void solve()
{
    int n, c;
    cin >> n >> c;

    v(int) A(n);

    for (int &x : A)
        cin >> x;

    int l = 0;
    int r = 1e9;

    sort(all(A));

    while (r - l > 1)
    {

        int m = l + (r - l) / 2;

        if (good(A, m, c))
            l = m;
        else
            r = m;
    }
    cout << l << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// 1 2 4 8 9