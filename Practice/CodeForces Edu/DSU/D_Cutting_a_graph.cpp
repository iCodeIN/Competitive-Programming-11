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

struct item
{
    string s;
    int u;
    int v;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;

    cin >> n >> m >> q;

    init();

    while (m--)
    {
        // ignore
        int u;
        int v;
        cin >> u >> v;
    }

    item Q[q];

    for (int i = 0; i < q; i++)
        cin >> Q[i].s >> Q[i].u >> Q[i].v;

    stack<bool> st;
    // processing queries in reverse order
    for (int i = q - 1; i >= 0; i--)
    {
        if (Q[i].s == "ask")

            st.push(get(Q[i].u) == get(Q[i].v));
        else
            Union(Q[i].u, Q[i].v);
    }

    while (st.size())
    {
        if (st.top())
            cout << "YES\n";
        else
            cout << "NO\n";

        st.pop();
    }
}