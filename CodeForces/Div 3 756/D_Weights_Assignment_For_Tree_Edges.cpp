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

#define pair <int, int> pii
#define ff first
#define ss second

#define int long long
#define mod 1000000007ll
#define endl "\n"
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
void solve()
{
    int n;
    cin >> n;

    v(int) P(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> P[i];

    v(int) perm(n);
    for (int &x : perm)
        cin >> x;
    bool ans = P[perm[0]] == perm[0];

    if (ans)
    {
        v(int) idx(n + 1, -1);
        for (int i = 0; i < n; i++)
            idx[perm[i]] = i;

        for (int i = 1; i <= n; i++)
            if (idx[P[i]] > idx[i])
                ans = false;
        if (ans)
        {
            v(int) dist(n + 1, 0);
            int x = 1;
            for (int i = 1; i < n; i++)
            {
                dist[perm[i]] = x++;
            }

            v(int) Ans(n + 1);
            for (int i = n - 1; i >= 0; i--)
            {
                int cur = perm[i];
                Ans[cur] = dist[cur] - dist[P[cur]];
            }
            for (int i = 1; i <= n; i++)
                cout << Ans[i] << " ";
        }
    }

    if (!ans)
    {
        cout << -1;
    }
    cout << endl;
}
int32_t main()
{
    FastIO;

    w(T)
    {
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //+
