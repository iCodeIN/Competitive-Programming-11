

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

// #define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

const int inf = 1e7;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    v(int) Adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    v(int) dist(n + 1, inf);
    set<pair<int, int>> st;

    for (int i = 0; i < k; i++)
    {
        int u;
        cin >> u;
        st.insert({0, u});
        dist[u] = 0;
    }

    while (st.size() > 0)
    {
        pair<int, int> b = *st.begin();

        st.erase(st.begin());

        for (int x : Adj[b.second])
        {
            if (b.first + 1 < dist[x])
            {
                auto itr = st.find({dist[x], x});

                if (itr != st.end())
                    st.erase(itr);

                dist[x] = b.first + 1;
                st.insert({dist[x], x});
            }
        }
    }

    for (int i = 0; i <= n; i++)
        if (dist[i] == inf)
            dist[i] = -1;

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;
        cout << dist[x] << endl;
    }
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/*


*/