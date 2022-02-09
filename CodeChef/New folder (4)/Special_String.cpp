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

void dfs(string &s, int current, v<int> Adj[], int &ans, int lvl, int m, v<int> &indexAtLevel)
{

    indexAtLevel[lvl] = current;

    if (current < s.size() and s[current] == 'a' and lvl >= m)
        ans = min(ans, (indexAtLevel[lvl - m + 1] - current + 1) - m);

    for (auto child : Adj[current])
        dfs(s, child, Adj, ans, lvl + 1, m, indexAtLevel);

    indexAtLevel[lvl] = -1;
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int m;
    cin >> m;

    v<int> next(n, n);
    v<int> right(26, n);

    v<int> Adj[n + 1];

    for (int i = n - 1; i >= 0; i--)
    {
        int req = s[i] - 'a';
        req = (req + 1) % 26;
        Adj[right[req]].push_back(i);
        right[s[i] - 'a'] = i;
    }

    int ans = INT_MAX;

    v<int> indexAtLevel(n + 1, -1);

    dfs(s, n, Adj, ans, 0, m, indexAtLevel);

    ans = (ans == INT_MAX) ? -1 : ans;

    cout << ans << endl;
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