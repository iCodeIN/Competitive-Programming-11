

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

struct node
{
    int r1 = -1, r2 = -1;
    int c1 = -1, c2 = -1;
};
a bool operator<(node a, node b)
{

    return
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<node> A(n + 1);

    for (int i = 0; i < m; i++)
    {

        int x;
        cin >> x;

        for (int j = 0; j < x; j++)
        {
            int v;
            cin >> v;

            if (A[v].r1 == -1)
                A[v].r2 = i, A[v].c2 = j;
            else
                A[v].r1 = i, A[v].c1 = j;
        }
    }

    sort(A.begin(), A.end());
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //