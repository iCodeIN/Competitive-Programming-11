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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    init();

    while (q--)
    {
        string op;
        cin >> op;

        int a, b;
        cin >> a >> b;

        if (op == "union")
            Union(a, b);
        else
        {
            bool ans = get(a) == get(b);
            if (ans == false)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
}