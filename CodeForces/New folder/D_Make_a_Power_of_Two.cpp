

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

v(string) A;

int solve(string &a, string &b, int p1, int p2)
{

    if (p1 == a.length())
        return b.length() - p2;

    if (p2 == b.length())
        return a.length() - p1;

    if (a[p1] == b[p2])
        return solve(a, b, p1 + 1, p2 + 1);

    else
        return 1 + solve(a, b, p1 + 1, p2);
}
void solve()
{
    string s;
    cin >> s;

    int ans = INT32_MAX;

    for (int i = 0; i < A.size(); i++)
    {

        int c = solve(s, A[i], 0, 0);
        ans = min(ans, c);
    }

    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    int i = 1;
    unsigned int x = 1;

    while (i < 64)
    {

        string y = to_string(x);
        A.push_back(y);
        x <<= 1;
        i++;
    }

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //