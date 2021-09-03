

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

//  0 : i -> N + 1
//  1 : N + 1 -> i

void solve()
{
    int n;
    cin >> n;

    v(int) A(n);
    int c = 0;

    for (int &x : A)
    {
        cin >> x;
        c += x;
    }

    int t = n + 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (A[i] == 0)
        {
            t = i + 1;
            break;
        }
    }

    if (c == n)
    {

        cout << n + 1 << " ";

        for (int i = 1; i <= n; i++)
            cout << i << " ";
    }
    else
    {
        int x = 1;

        while (x <= t)
            cout << x++ << " ";

        cout << n + 1 << " ";

        while (x < n + 1)
            cout << x++ << " ";
    }
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