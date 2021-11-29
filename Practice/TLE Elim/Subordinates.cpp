#include <bits/stdc++.h>
using namespace std;

void dfs(int x, vector<int> Adj[], vector<int> &Ans)
{
    for (int child : Adj[x])
    {
        dfs(child, Adj, Ans);
        Ans[x] += 1 + Ans[child];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> parent(n + 1);

    for (int i = 2; i <= n; i++)
        cin >> parent[i];

    vector<int> Adj[n + 1];

    for (int i = 2; i <= n; i++)
    {
        // parent -> child
        int p = parent[i];
        int current = i;

        if (p != current)
            Adj[p].push_back(current);
    }

    vector<int> Ans(n + 1, 0);
    dfs(1, Adj, Ans);

    for (int i = 1; i <= n; i++)
        cout << Ans[i] << " ";
}