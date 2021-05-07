

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
#include <unordered_map>
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

int query(int l, int r)
{
    int temp;

    cout << "? " << l << " " << r << endl;
    fflush(stdout);
    cin >> temp;
    fflush(stdout);
    return temp;
}

void solve()
{
    int n;
    cin >> n;

    int t;
    cin >> t;

    int k;
    cin >> k;

    int l = 0;
    int r = n + 1;


    while (r - l > 1)
    {
        int m = (l + r) / 2;

        int sum = query(1, m);

        if (m - sum >= k)
            r = m;
        else
            l = m;
    }

    cout << "! " << r << endl;
}

int32_t main()
{
    // FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //