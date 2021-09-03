

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

struct node
{
    int idx;
    int v;
};
void solve()
{
    int n, k;
    cin >> n >> k;
    v(node) A(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i].v;
        A[i].idx = i;
    }

    sort(A.begin(), A.end(), [](node a, node b)
         { return a.v < b.v; });
    int parts = 0;
    for (int i = 0; i < n; i++)
    {

        int j = i + 1;

        while (j < n and A[j].idx - A[j - 1].idx == 1)
            j++;
        i = j - 1;
        parts++;
    }
    if (parts <= k)
        cout << "Yes";
    else
        cout << "No";

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
