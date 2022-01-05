// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
/* author : pasricha_dhruv */
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#include <bits/stdc++.h>
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
using namespace std;
using LL = long long int;
using LD = long double;
using vi = vector<LL>;
using pii = pair<LL, LL>;
const LL mod = 1e9 + 7;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#define all(x) x.begin(), x.end()
#define double LD
#define endl "\n"
#define ff first
#define int LL
#define ss second
#define v vector
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
struct node
{
    v<v<int>> Adj;
    int n = 0;
    string s;
};

void solve(int r, int p, v<int> Adj[], string &s, node &ans, int p_new)
{
    if (s[p] != s[r])
    {
        int n = ++ans.n;
        ans.Adj.push_back({});
        ans.Adj[p_new].push_back(n - 1);
        ans.Adj[n - 1].push_back(p_new);
        ans.s += s[r];
        p_new = n - 1;
    }

    for (int c : Adj[r])
    {
        if (c != p)
            solve(c, r, Adj, s, ans, p_new);
    }
}

node newTree(int root, int parent, v<int> Adj[], string &s)
{
    node ans;
    ans.Adj.push_back({});
    ans.n++;
    ans.s += 'B';
    for (int child : Adj[root])
        if (child != parent)
            solve(child, root, Adj, s, ans, 0);
    return ans;
}

int ans = 0;

void dfs(int root, int parent, v<int> Adj[], string &s, int cr, int cg)
{

    if (s[root] == 'B')
    {
        if (cr < 1 or cg < 1)
            ans++;
    }
    if (s[root] == 'B')
        cr = cg = 0;
    else if (s[root] == 'G')
        cg++;
    else
        cr++;
    for (int child : Adj[root])
    {
        if (child != parent)
        {
            dfs(child, root, Adj, s, cr, cg);
        }
    }
}

map<int, int> mp[2];
void count(int root, v<v<int>> &Adj, string &s, int p = -1, int gp = -2)
{

    if (s[root] == 'B')
    {
        mp[0][p]++;
        mp[1][gp]++;
    }

    for (int c : Adj[root])
    {
        if (c != p)
            count(c, Adj, s, root, p);
    }
}

bool check(int root, v<v<int>> &Adj, string &s, int p = -1)
{
    if (s[root] != 'B')
    {
        // cout << root << " -> ";
        // cout << mp[0][root] << endl;
        if (mp[0][root] > 1)
            return false;
    }

    bool ans = true;

    for (int c : Adj[root])
    {
        if (c != p)
        {
            ans &= check(c, Adj, s, root);
        }
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;
    s = 'x' + s;
    v<int> Adj[n + 1];

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    int root = n + 1;

    for (int i = 1; i <= n; i++)
        if (s[i] == 'B')
            root = min(root, i);

    ans = 0;

    if (root <= n)
        dfs(root, -1, Adj, s, 0, 0);
    if (root <= n and ans <= 1)
    {
        auto tree = newTree(root, -1, Adj, s);
        mp[0].clear();
        mp[1].clear();
        count(0, tree.Adj, tree.s);
        ans = check(0, tree.Adj, tree.s);
        if (ans == false)
            ans = INT_MAX;
    }
    if (ans <= 1)
        cout << "Yes";
    else
        cout << "No";
    cout << endl;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //