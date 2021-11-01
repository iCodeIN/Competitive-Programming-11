

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

void update(int i, int val, v(int) A[], int n)
{
    A[n][i] = val;
    i /= 2;
    for (int level = n - 1; level >= 0; level--)
    {
        int lc = A[level + 1][2 * i];
        int rc = A[level + 1][2 * i + 1];

        bool or_ = (n - level) & 1;
        if (or_)
            A[level][i] = lc | rc;
        else
            A[level][i] = lc ^ rc;

        i /= 2;
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;

    v(int) A[n + 1];

    for (int i = 0; i <= n; i++)
        A[i].resize(1 << i);

    for (int &x : A[n])
        cin >> x;

    for (int level = n - 1; level >= 0; level--)
    {
        bool or_ = (n - level) & 1;
        for (int i = 0; i < A[level].size(); i++)
        {
            int lc = A[level + 1][2 * i];
            int rc = A[level + 1][2 * i + 1];

            if (or_)
                A[level][i] = lc | rc;
            else
                A[level][i] = lc ^ rc;
        }
    }

    while (q--)
    {
        int idx, v;
        cin >> idx >> v;
        idx--;
        update(idx, v, A, n);
        cout << A[0][0] << endl;
    }
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //