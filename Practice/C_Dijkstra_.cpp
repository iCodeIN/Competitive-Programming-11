

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
#include <map>
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
    int n, m;
    cin >> n >> m;

    map<int, int> mp[n + 1];

    for (int i = 0; i < m; i++)
    {

        int u, v, w;
        cin >> u >> v >> w;
        if (u == v)
            continue;
        if (mp[u].count(v))
            mp[u][v] = min(mp[u][v], w);
        else
            mp[u][v] = w;
        mp[v][u] = mp[u][v];
    }

    vector<int> dist(n + 1, INT64_MAX);
    vector<int> prev(n + 1, -1);

    dist[1] = 0;

    set<pair<int, int>> st; // {dist,vertex}

    st.insert({0, 1});

    while (!st.empty())
    {
        auto current = *st.begin();
        int u = current.second;
        st.erase(st.begin());
        for (auto nb : mp[u])
        {
            int v = nb.first;
            int w = nb.second;

            if (w + dist[u] < dist[v])
            {

                auto itr = st.find({dist[v], v});
                if (itr != st.end())
                    st.erase(itr);
                dist[v] = w + dist[u];
                prev[v] = u;
                st.insert({dist[v], v});
            }
        }
    }

    if (dist[n] == INT64_MAX)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> path;

    int c = n;

    while (c != -1)
    {
        path.push_back(c);
        c = prev[c];
    }
    for (int i = (int)path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";

    cout << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //