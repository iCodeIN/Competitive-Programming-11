

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

struct Node
{
    int v;
    int idx;
    int ans;
};
void solve()
{
    int n, k;
    cin >> n >> k;

    v(Node) A(n);
    for (auto &x : A)
        cin >> x.v;

    for (int i = 0; i < n; i++)
        A[i].idx = i;

    sort(A.begin(), A.end(), [](Node &a, Node &b)
         { return a.v < b.v; });
    int x = k / n;
    int x_ = k % n;
    for (int i = 0; i < n; i++)
        A[i].ans = x;

    for (int i = 0; i < x_; i++)
        A[i].ans++;

    sort(A.begin(), A.end(), [](Node &a, Node &b)
         { return a.idx < b.idx; });

    for (auto x : A)
        cout << x.ans << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //