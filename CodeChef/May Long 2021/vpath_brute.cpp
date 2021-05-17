

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
// #include <algorithm>
// #include <bits/stdc++.h>
#include <cmath>
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

// #define int long long int
#define mod 1000000007
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

static int euler_tour[120000];
v(int) first_occ, getNode, getIdx, dist;
int idx = -1;
int pos = -1;
static int SPARSE[120000][40];
static int dp[3002];
static v(int) adj[3002];

void dfs(int v, int lvl)
{
    getIdx[v] = ++idx;
    getNode[idx] = v;
    first_occ[v] = ++pos;
    dist[v] = lvl;
    euler_tour[pos] = getIdx[v];

    for (int &x : adj[v])
    {
        if (getIdx[x] == -1)
        {
            dfs(x, lvl + 1);
            euler_tour[++pos] = getIdx[v];
        }
    }
}

void buildSparse(int n)
{

    int col = log2(n) + 1;

    for (int i = 0; i < n; i++)
        SPARSE[i][0] = euler_tour[i];

    for (int j = 1; j < col; j++)
    {
        int prev_window_size = (1 << (j - 1));
        for (int i = 0; i + prev_window_size < n; i++)
            SPARSE[i][j] = min(SPARSE[i][j - 1], SPARSE[i + prev_window_size][j - 1]);
    }
}

int query(int start, int end)
{
    if (start > end)
        swap(start, end);

    int window_size = end - start + 1;
    int w = log2(window_size);
    int ans = min(SPARSE[start][w], SPARSE[start + window_size - (1 << w)][w]);

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    // 
    idx = -1;
    pos = -1;
    
    // 
    first_occ.clear();
    getNode.clear();
    dist.clear();
    getIdx.clear();
    
    // 
    first_occ.assign(n + 1, -1);
    getIdx.assign(n + 1, -1);
    getNode.assign(n + 1, -1);
    dist.assign(n + 1, -1);
    
    
    dfs(1, 0);

    buildSparse(pos + 1);

    int ans = n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int lca_ = query(first_occ[i], first_occ[j]);
            lca_ = getNode[lca_];
            int d = dist[i] + dist[j] - 2 * dist[lca_];
            cout << i << " " << j << " " << dp[d-1] << endl;
            ans = (ans + dp[d - 1]) % mod;
        }
    }
    cout << ans << endl;

    for (int i = 1; i <= n; i++)
        adj[i].clear();
}

int32_t main()
{
    FastIO;
    dp[0] = 1;
    for (int i = 1; i <= 3001; i++)
        dp[i] = (dp[i - 1] * 2) % mod;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //