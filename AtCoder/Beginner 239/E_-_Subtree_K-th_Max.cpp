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
// #define int LL
#define ss second
#define v vector
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
// Precomputation
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
class PreCompute
{
public:
    static void preCompute()
    {
    }
};
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
// Solution
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
priority_queue<int, v<int>, greater<int>> pq[100001];
int value[100001];
v<v<int>> Adj;
class Solution
{

    static void dfs(int root, int parent = -1)
    {

        for (int child : Adj[root])
            if (child != parent)
                dfs(child, root);

        pq[root].push(value[root]);

        for (int child : Adj[root])
            if (child != parent)
            {
                auto temp = pq[child];

                while (temp.size())
                {
                    pq[root].push(temp.top());
                    temp.pop();

                    if (pq[root].size() > 20)
                        pq[root].pop();
                }
            }
    }

    static int query(int root, int k)
    {
        auto temp = pq[root];

        while (temp.size() > k)
            temp.pop();

        return temp.top();
    }

public:
    static void solve()
    {
        int n;
        cin >> n;

        int q;
        cin >> q;

        for (int i = 1; i <= n; i++)
            cin >> value[i];

        Adj.resize(n + 1);

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }

        dfs(1);

        for (int i = 0; i < q; i++)
        {
            int root, k;
            cin >> root >> k;
            cout << query(root, k) << endl;
        }
    }
};
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
// TestCases
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
class TestCases
{
public:
    static bool multiple;

    static void solve()
    {
        int t = 1;
        // PreCompute::preCompute();
        multiple and cin >> t;
        for (int i = 1; i <= t; i++)
        {
            // cout << "Case #" << i << ": ";
            Solution::solve();
        }
    }
};
bool TestCases::multiple = false;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    TestCases::solve();
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
