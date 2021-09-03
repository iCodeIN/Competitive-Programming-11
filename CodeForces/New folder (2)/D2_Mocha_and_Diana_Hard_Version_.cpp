

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

int get(int parent[], int x)
{

    if (parent[x] == x)
    {
        return x;
    }

    return parent[x] = get(parent, parent[x]);
}

void Union(int parent[], int size[], int x, int y)
{

    x = get(parent, x);
    y = get(parent, y);

    if (size[x] < size[y])
        swap(x, y);
    size[x] += size[y];
    parent[y] = x;
}

struct edge
{
    int u, v;
};

void solve()
{
    int n;
    cin >> n;

    int m1, m2;

    cin >> m1 >> m2;

    int parent1[n + 1];
    int size1[n + 1];
    int size2[n + 1];
    int parent2[n + 1];

    for (int i = 1; i <= n; i++)
        parent1[i] = parent2[i] = i, size1[i] = size2[i] = 1;

    for (int i = 1; i <= m1; i++)
    {

        int u, v;
        cin >> u >> v;

        Union(parent1, size1, u, v);
    }

    for (int i = 1; i <= m2; i++)
    {
        int u, v;
        cin >> u >> v;

        Union(parent2, size2, u, v);
    }

    v(edge) Ans;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (get(parent1, i) != get(parent1, j) and get(parent2, i) != get(parent2, j))
            {
                edge x;
                x.u = i;
                x.v = j;

                Ans.push_back(x);

                Union(parent1, size1, i, j);
                Union(parent2, size2, i, j);
            }
        }
    }

    cout << Ans.size() << endl;
    for (auto x : Ans)
        cout << x.u << " " << x.v << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //