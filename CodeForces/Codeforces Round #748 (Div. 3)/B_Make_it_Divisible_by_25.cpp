

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

int solve(string &s, int d1, int d0)
{

    int n = s.length();

    int i = n - 1;

    int ans = 0;
    while (i >= 0 and s[i] - '0' != d0)
        i--, ans++;

    if (i != -1)
        i--;
    
    while (i >= 0 and s[i] - '0' != d1)
        i--, ans++;

    if (i == -1)
        return INT32_MAX;

    return ans;
}

void solve()
{
    string s;
    cin >> s;

    // 00, 25, 50, 75

    int A[] = {0, 2, 5, 7};
    int B[] = {0, 5, 0, 5};

    int ans = INT32_MAX;

    for (int i = 0; i < 4; i++)
        ans = min(ans, solve(s, A[i], B[i]));

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