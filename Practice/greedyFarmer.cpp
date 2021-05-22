

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

bool isGood(v(int) & A, int mx, int k)
{
    int div_required = 0;
    for (int &x : A)
    {
        if (x > mx)
            div_required += (x / mx) - (x % mx == 0);
    }

    return div_required <= k;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    v(int) A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int mx = A[0];
    for (int &x : A)
        mx = max(mx, x);

    int l = 0;
    int r = mx + 1;

    while (r - l > 1)
    {
        int m = (l + r) / 2;

        if (isGood(A, m, k))
            r = m;
        else
            l = m;
    }

    cout << r << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //