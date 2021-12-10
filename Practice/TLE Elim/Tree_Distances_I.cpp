#include <bits/stdc++.h>
using namespace std;

int solveDown(int root, vector<int> *Adj, int parent, vector<vector<int>> &down)
{
    int mx = 0;
    int smx = 0;

    for (int child : Adj[root])
    {
        if (child == parent)
            continue;

        int cur = 1 + solveDown(child, Adj, root, down);

        if (cur > mx)
        {
            smx = mx;
            mx = cur;
        }
        else if (cur > smx)
            smx = cur;
    }

    down[root][0] = mx;
    down[root][1] = smx; 

    return mx;
}

void solveUp(int root, vector<int> *Adj, int parent, vector<vector<int>> &down, vector<int> &up)
{
    if (parent != -1)
    {
        if (down[root][0] + 1 == down[parent][0])
            up[root] = 1 + down[parent][1];
        else
            up[root] = 1 + down[parent][0];

        up[root] = max(up[root], 1 + up[parent]);
    }

    for (int child : Adj[root])
    {
        if (child == parent)
            continue;

        solveUp(child, Adj, root, down, up);
    }
}

int main()
{
    int n;
    cin >> n;

    auto Adj = new vector<int>[n + 1];

    for (int i = 0; i < n - 1; i++)
    {
        int u;
        int v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    vector<int> up(n + 1, 0);
    vector<vector<int>> down(n + 1, vector<int>(2, 0));

    solveDown(1, Adj, -1, down);
    solveUp(1, Adj, -1, down, up);

    for (int i = 1; i <= n; i++)
        cout << max(up[i], down[i][0]) << " ";
}