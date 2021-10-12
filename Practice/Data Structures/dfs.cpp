#include <bits/stdc++.h>
using namespace std;

void dfs(int x, vector<int> Adj[], vector<bool> &visited)
{
    visited[x] = true;
    cout << x << " ";
    for (int nb : Adj[x])
        if (!visited[nb])
            dfs(nb, Adj, visited);
}

void bfs(int x, vector<int> Adj[], vector<bool> &visited)
{
    queue<int> q;
    q.push(x);
    visited[x] = true;

    while (!q.empty())
    {
        int x = q.front();
        cout << x << " ";

        for (int nb : Adj[x])
            if (!visited[nb])
                visited[nb] = true, q.push(nb);
        q.pop();
    }
}

void printTraversals(int n, int m, vector<pair<int, int>> &edges)
{

    vector<int> Adj[n + 1];
    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;

        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs(i, Adj, visited);

    cout << endl;

    for (int i = 0; i <= n; i++)
        visited[i] = false;

    for (int i = 1; i <= n; i++)
        if (!visited[i])
            bfs(i, Adj, visited);
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);

    for (auto &edge : edges)
        cin >> edge.first >> edge.second;

    printTraversals(n, m, edges);
}

