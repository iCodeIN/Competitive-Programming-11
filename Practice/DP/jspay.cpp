#include <bits/stdc++.h>
using namespace std;

#define v vector

struct triplet
{
    int type;
    string nodeName;
    int uid;
};

void print(bool b)
{
    if (b)
        cout << "true";
    else
        cout << "false";

    cout << "\n";
}

void lock(string &nodeName, map<string, int> &index, map<string, int> &status, v<string> &Nodes)
{
    int idx = index[nodeName];
    int child1 = idx << 1;
    int child2 = child1 + 1;
    bool ans = true;
    if (status[nodeName] == 1 or status[nodeName] == -1)
        ans = false;
    else
    {
        int p = idx >> 1;
        status[Nodes[p - 1]] = -1;
        status[nodeName] = 1;
    }
    print(ans);
}

void unlock(string &node, map<string, int> &status)
{
    bool ans = status[node];
    if (status[node] == 1)
        status[node] = 0;
    print(ans);
}

void upgrade(string &nodeName, map<string, int> &index, map<string, int> &status, v<string> &Nodes)
{
    int idx = index[nodeName];
    int child1 = idx << 1;
    int child2 = child1 + 1;
    bool ans = true;
    int n = Nodes.size();
    if (child1 >= 1 and child1 < n and child2 >= 1 and child2 < n)
    {
        if (status[Nodes[child1 - 1]] == 1 and status[Nodes[child2 - 1]] == 1)
        {
            status[Nodes[child1 - 1]] = 0;
            status[Nodes[child2 - 1]] = 0;
            status[Nodes[idx - 1]] = 0;
        }
        else
            ans = false;
    }
    print(ans);
}

void solve()
{
    int n, m, apis;
    cin >> n >> m >> apis;

    v<string> Nodes(n);
    for (auto &node : Nodes)
        cin >> node;

    map<string, int> index;

    for (int i = 0; i < n; i++)
        index[Nodes[i]] = i + 1;

    v<triplet> queries(apis);
    for (auto &query : queries)
        cin >> query.type >> query.nodeName >> query.uid;

    map<string, int> status;
    for (auto &query : queries)
        status[query.nodeName] = 0;

    for (auto &query : queries)
    {
        switch (query.type)
        {
        case 1:
            lock(query.nodeName, index, status, Nodes);
            break;
        case 2:
            unlock(query.nodeName, status);
            break;
        case 3:
            upgrade(query.nodeName, index, status, Nodes);
            break;
        default:
            break;
        }
    }
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}