

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

void add(int &x, v(v(int)) & A, int i, int j)
{
    // cout << i << " " << j << endl;
    while (i < A.size() and j < A.size())
        A[i++][j++] = ++x;
}

void solve()
{
    int n;
    cin >> n;

    if (n == 2)
    {
        cout << -1 << endl;
        return;
    }

    
    v(v(int)) A(n, v(int)(n));

    int i = 0, j = 0;
    int x = 0;
    int t = 0;
    int p = 2;
    while (x < n * n)
    {
        add(x, A, i, j);

        if (t % 2 == 0)
            j = p / 2, i = 0;
        else
            i = p / 2, j = 0;

        t++;
        p++;
    }

    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < n; j++)
            cout << A[i][j] << " ";
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //