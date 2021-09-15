

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
const int N = 3 * 1e5;
int X[N + 1] = {0};

void solve()
{
    int mex, x;
    cin >> mex >> x;

    int left_xor = X[mex - 1];

    int ans = left_xor ^ x;

    if (left_xor == x)
        cout << mex;
    else if (ans != mex)
        cout << mex + 1;
    else
        cout << mex + 2;

    cout << endl;
}

int32_t main()
{
    FastIO;
    for (int i = 1; i <= N; i++)
        X[i] = X[i - 1] ^ i;
    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //