#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int parent[N + 1];
int Size[N + 1];

int get(int a)
{
    return parent[a] = (parent[a] == a) ? a : get(parent[a]);
}

void Union(int a, int b)
{
    a = get(a);
    b = get(b);

    if (a == b)
        return;
    if (Size[a] > Size[b])
    {
        Size[a] += Size[b];
        parent[b] = parent[a];
    }
    else
    {
        Size[b] += Size[a];
        parent[a] = parent[b];
    }
}

void init()
{
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
        Size[i] = 1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();

    int n, m;
    cin >> n >> m;

    int A[N + 1][3];

    multiset<pair<int, int>> st;

    for (int i = 1; i <= n; i++)
    {

        cin >> A[i][1] >> A[i][2];
        st.insert({i, 1});
        st.insert({i, 2});
    }

    pair<int, int> Q[m];

    for (int i = 0; i < m; i++)
    {
        cin >> Q[i].first >> Q[i].second;
        st.erase({Q[i].first, Q[i].second});
    }

    int Ans[n + 1];

    for (int i = 1; i <= n; i++)
        Ans[i] = INT32_MAX;
    Ans[1] = -1;
    int t = 0;

    while (st.size() > 0)
    {
        auto x = *st.begin();

        int u = x.first;
        int v = A[x.first][x.second];

        if (u != -1 and v != -1)
        {
            Union(u, v);
        }

        t++;
        // cout << "mai multiset m hu " << x.first << "  " << x.second << endl;
        st.erase(x);
    }
    for (int i = 1; i <= n; i++)
        cout << parent[i] << " ";

    cout << endl;
    for (int i = m - 1; i >= 0; i--)
    {
        int u = Q[i].first;
        int v = A[u][Q[i].second];

        if (u != -1 and v != -1)
        {
            Union(u, v);

            int u_ = get(u);

            if (u_ == get(1))
            {
                if (Ans[u] == INT32_MAX)
                    Ans[u] = 2 * n - t;
                if (Ans[v] == INT32_MAX)
                    Ans[v] = 2 * n - t;
            }
        }

        t++;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << Ans[i] << "\n";
    }
}