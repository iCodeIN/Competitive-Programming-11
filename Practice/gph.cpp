

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

bool solve(string a, string b)
{
    string a_odd = "";
    string b_odd = "";
    string a_even = "";
    string b_even = "";
    for (int i = 0; i < a.length(); i++)
        if (i & 1)
            a_odd += a[i];
        else
            a_even += a[i];
    for (int i = 0; i < b.length(); i++)
        if (i & 1)
            b_odd += b[i];
        else
            b_even += b[i];

    sort(all(a_odd));
    sort(all(a_even));

    sort(all(b_odd));
    sort(all(b_even));

    return a_odd == b_odd and a_even == b_even;
}

int32_t main()
{
    FastIO;

    w(T)
        solve("", "");

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //