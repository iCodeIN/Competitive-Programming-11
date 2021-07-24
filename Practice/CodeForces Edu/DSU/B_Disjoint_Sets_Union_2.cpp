#include <bits/stdc++.h>
using namespace std;

const int N = 3 * 1e5 + 5;

int parent[N + 1];
int Size[N + 1];
int Minimal[N + 1];
int Maximal[N + 1];

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
        Maximal[a] = max(Maximal[a], Maximal[b]);
        Minimal[a] = min(Minimal[a], Minimal[b]);
        parent[b] = parent[a];
    }
    else
    {
        Size[b] += Size[a];
        Maximal[b] = max(Maximal[a], Maximal[b]);
        Minimal[b] = min(Minimal[a], Minimal[b]);
        parent[a] = parent[b];
    }
}

void init()
{
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
        Size[i] = 1;
        Minimal[i] = i;
        Maximal[i] = i;
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

        if (op == "union")
        {
            int a, b;
            cin >> a >> b;
            Union(a, b);
        }
        else
        {
            int a;
            cin >> a;
            a = get(a);
            cout << Minimal[a] << " " << Maximal[a] << " " << Size[a] << "\n";
        }
    }
}