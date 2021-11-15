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

    v(int) P(n + 1, -1);

    v(int) A(n + 1), B(n + 1);

    cin >> B[1];
    for (int i = 2; i <= n; i++)
    {
        cin >> P[i];
        cin >> A[i] >> B[i];
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        int ans = 0;
        set<set<int>> st;

        pair<int, int> X[] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        for (int i = 0; i < 4; i++)
        {
            set<int> temp;
            temp.insert(a);
            temp.insert(b);
            if (X[i].first == 1 and a != 1)
            {
                temp.insert(P[a]);
            }
            if (X[i].second == 1 and b != 1)
            {
                temp.insert(P[b]);
            }
            st.insert(temp);
        }

        for (auto s : st)
        {
            int cur = 1;

            if (s.count(P[a]))
                cur = A[a];
            else
                cur = B[a];

            if (s.count(P[b]))
                cur *= A[b];
            else
                cur *= B[b];

            ans += cur;
            cout << cur << endl;
        }
        cout << ans << " ";
    }
    cout << endl;
}

int32_t main()
{
    FastIO;
    int test = 1;
    w(T)
    {
        cout << "Case #" << test++ << ": ";
        solve();
    }
    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //