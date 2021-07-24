#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 5;

int parent[N + 1];
int Size[N + 1];
int Points[N + 1];

pair<int, int> get(int a)
{
    if (parent[a] == a)
        return {a, Points[a]};

    auto x = get(parent[a]);

    parent[a] = x.first;
    int actualPoints = x.second + Points[a];

    Points[a] = actualPoints - Points[parent[a]];

    return {x.first, actualPoints};
}

void Union(int a, int b)
{
    a = get(a).first;
    b = get(b).first;

    if (a == b)
        return;

    if (Size[a] > Size[b])
    {
        Size[a] += Size[b];
        Points[b] -= Points[a];
        parent[b] = parent[a];
    }
    else
    {
        Size[b] += Size[a];
        Points[a] -= Points[b];
        parent[a] = parent[b];
    }
}

void init()
{
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
        Size[i] = 1;
        Points[i] = 0;
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

        if (op == "join")
        {

            int a, b;
            cin >> a >> b;
            Union(a, b);
        }
        else if (op == "get")
        {
            int a;
            cin >> a;
            cout << get(a).second << "\n";
        }
        else
        {
            int a, b;
            cin >> a >> b;

            a = get(a).first;
            Points[a] += b;
        }
    }
}