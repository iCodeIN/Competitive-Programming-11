

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
#include <set>
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
    int n, q;
    cin >> n >> q;

    set<int> left;  // lowerbound
    set<int> right; // just smaller => negative lowerbound

    v(int) A(n);
    for (int &x : A)
        cin >> x;
    v(int) Q(q);
    for (int &x : Q)
        cin >> x;

    for (int i = 0; i < n; i++)
        if (A[i] == 1)
            right.insert(-(i + 1));
        else if (A[i] == 2)
            left.insert(i + 1);

    for (int x : Q)
    {

        int ans1 = (left.lower_bound(x) == left.end()) ? n + 1 : *left.lower_bound(x);

        int ans2 = (right.lower_bound(-x) == right.end()) ? n + 1 : *right.lower_bound(-x);

        int ans = n + 1;

        if (ans1 != n + 1)
            ans = min(ans, ans1 - x);

        if (ans2 != n + 1)
            ans = min(ans, x + ans2);

        if (ans == n + 1)
            ans = -1;
        if (x == 1)
            ans = 0;
        cout << ans << " ";
    }
    cout << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //