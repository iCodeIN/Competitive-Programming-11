

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

int nCr(int n, int r)
{

    int num = 1;
    int den = 1;

    for (int i = 0; i < r; i++)
        num *= (n - i), den *= (i + 1);

    return num / den;
}

void solve()
{
    int n;
    cin >> n;

    int q;
    cin >> q;

    int A[n];

    for (int i = 0; i < n; i++)
        cin >> A[i];

    int preOdd[n + 1] = {0};
    int preEven[n + 1] = {0};

    for (int i = 1; i <= n; i++)
    {
        if (A[i - 1] & 1)
            preOdd[i]++;
        else
            preEven[i]++;

        preOdd[i] += preOdd[i - 1];
        preEven[i] += preEven[i - 1];
    }

    while (q--)
    {

        int l, r;
        cin >> l >> r;

        int odd = preOdd[r] - preOdd[l - 1];
        int even = preEven[r] - preEven[l - 1];

        int ans = 0;

        if (odd >= 2 and even >= 1)
            ans += nCr(odd, 2) * nCr(even, 1);

        if (even >= 3)
            ans += nCr(even, 3);

        cout << ans << endl;
    }
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //