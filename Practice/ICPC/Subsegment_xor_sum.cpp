

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

void solve()
{

    int n;
    cin >> n;

    v(int) A(n);
    for (int &x : A)
        cin >> x;

    int ans = 0;

    int m = 1;

    for (int i = 0; i < 31; i++)
    {
        int c_odd = 0;
        bool odd = false;

        for (int j = 0; j < n; j++)
        {
            if ((A[j] & (1 << i)) > 0)
                odd = (!odd);
            if (odd)
                c_odd++;
        }

        for (int j = 0; j < n; j++)
        {
            int v = (m * c_odd) % mod;
            ans = (ans + v) % mod;

            if ((A[j] & (1 << i)) > 0)
                c_odd = (n - j - c_odd);
        }
        m = (m * 2) % mod;
    }
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
