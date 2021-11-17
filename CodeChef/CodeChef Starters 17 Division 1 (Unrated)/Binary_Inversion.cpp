

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
    string s;
    int c;
};

bool cmp(Node a, Node b)
{
    if (a.c == b.c)
        return a.s < b.s;
    return a.c < b.c;
}

void solve()
{
    int m, n;
    cin >> m >> n;

    v(Node) A(m);

    for (auto &x : A)
        cin >> x.s;

    for (int i = 0; i < m; i++)
        for (char ch : A[i].s)
            A[i].c += (ch == '1');

    sort(all(A), cmp);

    int ans = 0;
    int pre = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            pre += (A[i].s[j] == '1');
            ans += (A[i].s[j] == '0') ? pre : 0;
        }

    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //