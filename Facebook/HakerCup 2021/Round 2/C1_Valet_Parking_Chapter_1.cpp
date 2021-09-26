// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
#include <bits/stdc++.h>
// #include <cmath>
// #include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>
// #include <vector>

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
    int m, n, k;
    cin >> m >> n >> k;

    v(string) A(m);

    k--;

    for (string &s : A)
        cin >> s;

    set<int> up;
    set<int> down;

    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] == '.' and A[k][j] == 'X')
                up.insert(j);

    for (int i = k + 1; i < m; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] == '.' and A[k][j] == 'X')
                down.insert(j);

    int ans1 = 1;
    int ans2 = 1;
    int ans3 = 0;

    // only up
    for (int j = 0; j < n; j++)
    {
        if (A[k][j] == 'X')
        {
            if (up.find(j) == up.end())
                ++ans1;
        }
    }

    // only down
    for (int j = 0; j < n; j++)
    {
        if (A[k][j] == 'X')
        {
            if (down.find(j) == down.end())
                ++ans2;
        }
    }

    for (int j = 0; j < n; j++)
    {
        if (A[k][j] == 'X')
        {
            ++ans3;
        }
    }

    cout << min({ans1, ans2, ans3}) << endl;
}
int32_t main()
{
    FastIO;
    int test = 1;
    w(T)
    {
        cout << "Case #" << test++ << ": ";
        solve();
    }
    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //