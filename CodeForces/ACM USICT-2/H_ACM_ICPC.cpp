

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

bool solve(v(int) & A, int n, int k, int p)
{
    if (k == 0 and p == 0)
        return true;
    if (n == 0)
        return false;

    if (p == 0)
        return false;

    bool ans = solve(A, n - 1, k, p);

    if (ans == false and A[n - 1] <= k)
        ans = solve(A, n - 1, k - A[n - 1], p - 1);

    return ans;
}

void solve()
{
    int n = 6;
    v(int) A(n);
    for (int &x : A)
        cin >> x;

    int sum = 0;

    for (int &x : A)
        sum += x;
    bool ans = true;
    if (sum & 1)
        ans = false;
    else
        ans = solve(A, n, sum / 2, 3);

    if (ans)
        cout << "YES";
    else
        cout << "NO";
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //