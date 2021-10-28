

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

struct node
{
    int vertex;
    int degree;

    bool operator<(const node &a) const
    {
        if (this->degree != a.degree)
            return this->degree < a.degree;
        return this->vertex < a.vertex;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    v(int) Adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    // solving starts here
    set<node> st;
    v(int) degree(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        degree[i] = Adj[i].size();
        node temp;
        temp.vertex = i;
        temp.degree = degree[i];
        st.insert(temp);
    }

    v(int) Ans(n + 1, -1);

    int wt = n + 1;
    while (st.size() > 0)
    {
        auto itr = st.begin();
        node current = *itr;
        st.erase(itr);
        Ans[current.vertex] = --wt;
        for (int nb : Adj[current.vertex])
        {
            if (Ans[nb] == -1)
            {
                node temp;
                temp.vertex = nb;
                temp.degree = degree[nb];
                st.erase(temp);
                degree[nb]--;
                temp.degree = degree[nb];
                st.insert(temp);
            }
        }
    }

    int mx = 0;
    int mn = 1e9;
    for (int i = 1; i <= n; i++)
    {
        int d_i = 0;
        for (int nb : Adj[i])
            d_i += Ans[i] > Ans[nb];

        mx = max(d_i, mx);
        mn = min(d_i, mn);
    }

    cout << mx - mn << endl;
    for (int i = 1; i <= n; i++)
        cout << Ans[i] << " ";
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