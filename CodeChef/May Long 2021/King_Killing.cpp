

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>
#include <vector>

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

using namespace std;

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#define w(T)  \
    int T;    \
    cin >> T; \
    while (T--)

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define v(Type) vector<Type>
#define all(x) x.begin(), x.end()

#define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
static v(int) adj[200004];

struct node
{
    int days;
    v(int) deepest_nodes;
};

void merge(node *&ans, node *&temp)
{
    if (ans == NULL)
        ans = temp;
    else
        for (int &x : temp->deepest_nodes)
            ans->deepest_nodes.push_back(x);
}

void solve(int v, v(bool) & visited, v(int) & dp, node *&ans, int t)
{
    visited[v] = true;
    bool leaf = true;

    // cout << v << " " << t << " " << dp[v] << endl;

    for (int &x : adj[v])
        if (!visited[x])
        {
            leaf = false;
            if (t < dp[v])
                solve(x, visited, dp, ans, t);
            else if (t == dp[v] and dp[v] - dp[x] <= 1)
                solve(x, visited, dp, ans, t - 1);
            else
                visited[x] = true;
        }

    if (leaf)
    {
        if (dp[v] >= t)
            ans->deepest_nodes.push_back(v);
    }
}
node *solve(int v, v(bool) & visited, v(int) & dp)
{
    visited[v] = true;

    node *ans = NULL;
    vector<node *> A;
    for (int &x : adj[v])
        if (!visited[x])
            A.push_back(solve(x, visited, dp));

    if (A.size() == 0)
    {
        ans = new node;
        ans->days = 1;
        // ans->deepest_nodes.push_back(v);
    }
    else
    {
        int minDays = A[0]->days;

        for (int i = 1; i < A.size(); i++)
            minDays = min(A[i]->days, minDays);
        bool allMin = true;

        for (int i = 0; i < A.size(); i++)
            allMin &= (A[i]->days == minDays);

        if (allMin)
            for (int i = 0; i < A.size(); i++)
                merge(ans, A[i]);
        else
            for (int i = 0; i < A.size(); i++)
                if (A[i]->days > minDays)
                    merge(ans, A[i]);

        ans->days = minDays + 1 + (!allMin);
    }
    dp[v] = ans->days;
    return ans;
}

node *f(int n)
{
    v(bool) visited(n + 1, false);
    visited[1] = true;
    v(int) dp(n + 1);
    int minDays = INT32_MAX;
    v(node *) children(adj[1].size());
    for (int i = 0; i < adj[1].size(); i++)
    {
        node *temp = solve(adj[1][i], visited, dp); // return minDays for that subtree
        children[i] = temp;
        minDays = min(minDays, temp->days);
    }

    node *ans = new node;
    visited.clear();
    visited.assign(n + 1, false);
    visited[1] = true;
    for (int i = 0; i < adj[1].size(); i++)
    {
        if (children[i]->days == minDays)
        {
            node *temp = new node;
            solve(adj[1][i], visited, dp, temp, dp[adj[1][i]]);
            merge(ans, temp);
        }
    }
    ans->days = minDays;
    return ans;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto ans = f(n);

    sort(all(ans->deepest_nodes));

    cout << ans->deepest_nodes.size() << " " << ans->days << endl;
    for (int &x : ans->deepest_nodes)
        cout << x << " ";

    cout << endl;

    for (int i = 1; i <= n; i++)
        adj[i].clear();
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //