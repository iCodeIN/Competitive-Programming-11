

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
    int n, m;
    cin >> n >> m;

    int A[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    int Col[m];

    for (int j = 0; j < m; j++)
    {
        Col[j] = (A[0][j]) % 7;
        if (Col[j] == 0)
            Col[j] = 7;
    }
    bool ok = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m - 1; j++)
            ok &= ((A[i][j + 1] - A[i][j]) == 1);

    for (int j = 0; j < m; j++)
        for (int i = 0; i < n - 1; i++)
            ok &= ((A[i + 1][j] - A[i][j]) == 7);

    for (int j = 0; j < m - 1; j++)
        ok &= (Col[j + 1] - Col[j] == 1);

    if (ok)
        cout << "Yes";
    else
        cout << "No";
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //