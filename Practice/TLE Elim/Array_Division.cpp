

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

bool good(v(int) & A, int x, int k)
{
    int cur = 0;
    int count = 0;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        if (cur + A[i] <= x)
            cur += A[i];
        else if (A[i] <= x)
            cur = A[i], count++;
        else
            return false;
    }
    return count < k;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    v(int) A(n);

    for (int &x : A)
        cin >> x;

    int l = 0;
    int r = 1e18;

    while (r - l > 1)
    {
        int m = l + (r - l) / 2;

        if (good(A, m, k))
            r = m;
        else
            l = m;
    }
    cout << r << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //