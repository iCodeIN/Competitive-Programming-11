

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

bool comp(v(int) & A, v(int) & B)
{
    return A[0] + A[1] + A[2] > B[0] + B[1] + B[2];
}

int bs(v(v(int)) & A, int sum)
{

    // leftmost <= sum

    int l = -1;
    int r = A.size();

    while (r - l > 1)
    {
        int m = (l + r) >> 1;

        if (A[m][0] + A[m][1] + A[m][2] <= sum)
            r = m;
        else
            l = m;
    }
    return r + 1;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    v(v(int)) A(n, v(int)(3));

    for (auto &v : A)
        cin >> v[0] >> v[1] >> v[2];

    auto B = A;
    sort(all(A), comp);

    for (int i = 0; i < n; i++)
    {
        int ans = bs(A, B[i][0] + B[i][1] + B[i][2] + 300);
        if (ans <= k)
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
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