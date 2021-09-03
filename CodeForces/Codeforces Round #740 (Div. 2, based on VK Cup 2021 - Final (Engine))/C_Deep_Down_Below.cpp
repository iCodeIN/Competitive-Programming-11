

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
    int m;
    int s;
};

bool comp(node a, node b)
{

    if (a.m == b.m)
        return a.s > b.s;

    return a.m < b.m;
}

bool good(int x, v(node) & B)
{
    int n = B.size();
    int nodesTravelled = 0;
    for (int i = 0; i < n; i++)
    {
        if (B[i].m >= x + nodesTravelled)
            return false;

        nodesTravelled += B[i].s;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> A[n];

    for (int i = 0; i < n; i++)
    {
        int size;
        cin >> size;

        A[i].resize(size);
        for (int j = 0; j < size; j++)
            cin >> A[i][j];
    }
    vector<node> B(n);
    for (int i = 0; i < n; i++)
    {
        int mx = A[i][0];

        for (int j = 0; j < A[i].size(); j++)
            mx = max(mx, A[i][j] - j);

        B[i].m = mx;
        B[i].s = A[i].size();
    }

    sort(all(B), comp);

    int ans = 0;
    int nodesTravelled = 0;

    int l = -1;
    int r = 1e18;

    while (r - l > 1)
    {

        int m = (l + r) >> 1;

        if (good(m, B))
            r = m;
        else
            l = m;
    }

    cout << r << endl;
}
int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //