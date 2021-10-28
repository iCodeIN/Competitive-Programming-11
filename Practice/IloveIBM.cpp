

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

#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#define ll long long int

ll solve(vector<int> &A, int n, int cuts, int prev)
{

    if (n == 0)
    {
        if (cuts == 0)
            return A[prev];
        else
            return INT32_MAX;
    }
    ll newPrev = (A[n - 1] > A[prev]) ? n - 1 : prev;
    ll ans1 = solve(A, n - 1, cuts, newPrev);
    ll ans2 = (cuts > 0) ? A[prev] + solve(A, n - 1, cuts - 1, n - 2) : INT32_MAX;
    return min(ans1, ans2);
}

int32_t main()
{
    FastIO;

    int n;
    cin >> n;
    v(int) A(5);
    for (int &x : A)
        cin >> x;
    int days;
    cin >> days;

    cout << solve(A, A.size(), days - 1, n - 1);
    return 0;
}

// // //  // // //  // // //  // // // // // //  /
