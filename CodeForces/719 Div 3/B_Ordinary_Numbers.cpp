

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

v(int) A;

int add(int len, int d)
{
    string s = "";
    char ch = d + '0';
    for (int i = 0; i < len; i++)
        s += ch;

    return stoll(s);
}

void pre()
{
    for (int len = 1; len < 10; len++)
    {
        for (int d = 1; d <= 9; d++)
            A.push_back(add(len, d));
    }
}

int solve(int x)
{
    int l = -1;
    int r = A.size();

    while (r - l > 1)
    {
        int m = (l + r) / 2;

        if (A[m] <= x)
            l = m;
        else
            r = m;
    }

    return l + 1;
}

void solve()
{
    int n;
    cin >> n;

    int ans = solve(n);

    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    pre();
    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //