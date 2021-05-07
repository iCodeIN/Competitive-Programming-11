

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
#include <unordered_map>
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

int query(int l, int r, unordered_map<int, int> &A)
{
    int temp;
    if (A.count(r) > 0)
        return A[r];
    cout << "? " << l << " " << r << endl;
    fflush(stdout);
    cin >> temp;
    fflush(stdout);
    return A[r] = temp;
}

void solve()
{
    int n;
    cin >> n;

    unordered_map<int, int> A;
    int t;
    cin >> t;

    while (t--)
    {

        int k;
        cin >> k;

        int l = 0;
        int r = n + 1;

        while (r - l > 1)
        {
            int m = (l + r) / 2;

            int sum = query(1, m, A);

            if (m - sum >= k)
                r = m;
            else
                l = m;
        }
        cout << "! " << r << endl;
        fflush(stdout);

        for (auto &x : A)
            if (x.first >= r)
                A[x.first]++;
    }
}

int32_t main()
{
    // FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //