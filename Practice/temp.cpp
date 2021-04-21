#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int wt;
    int parent;
    int vertex;
    Node()
    {
        wt = INT32_MAX;
        parent = -1;
        vertex = -1;
    }
};

void explore(int x, vector<vector<int>> &adjMatrix, vector<Node> &vc, vector<bool> &visited)
{
    visited[x] = true;
    for (int j = 0; j < vc.size(); j++)
        if (adjMatrix[x][j] and !visited[j] and vc[j].wt >= adjMatrix[x][j])
            vc[j].wt = adjMatrix[x][j], vc[j].parent = x;
}

Node findMin(vector<Node> &vc, vector<bool> &visited)
{
    Node ans;
    for (int i = 0; i < vc.size(); i++)
        if (!visited[i] and vc[i].wt < ans.wt)
            ans = vc[i];
    return ans;
}
int main()
{
    int v, e;
    cin >> v >> e;

    vector<bool> visited(v, false);
    vector<vector<int>> adjMatrix(v, vector<int>(v));

    for (int i = 0; i < e; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;

        adjMatrix[v1][v2] = wt;
        adjMatrix[v2][v1] = wt;
    }

    vector<Node> vc(v);

    vc[0].wt = 0;

    for (int i = 0; i < v; i++)
        vc[i].vertex = i;

    for (int i = 0; i < v; i++)
    {
        Node x = findMin(vc, visited);
        // cout << x.vertex << endl;
        explore(x.vertex, adjMatrix, vc, visited);
    }

    for (int i = 1; i < v; i++)
        if (vc[i].parent != -1)
            cout << min(i, vc[i].parent) << " " << max(i, vc[i].parent) << " " << vc[i].wt << endl;
    return 0;
}