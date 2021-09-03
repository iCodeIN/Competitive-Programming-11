

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

int f(int n)
{

    // i* i <= n  max(i)

    int l = 0;
    int r = 1e9;

    while (r - l > 1)
    {

        int m = (l + r) >> 1;

        if (m * m <= n)
            l = m;
        else
            r = m;
    }

    return l;
}

void solve()
{
    int n;
    cin >> n;

    int a = f(n);
    int b = a + 1;

    int A = a * a;
    int B = b * b;

    int r, c;

    int d1 = n - A;
    int d2 = B - A;

    if (d1 == 0)
    {
        r = a;
        c = 1;
    }
    else if ((d2 / 2) < d1)
    {
        r = b;
        c = B - n + 1;
    }
    else
    {
        r = n - A;
        c = b;
    }

    cout << r << " " << c << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //