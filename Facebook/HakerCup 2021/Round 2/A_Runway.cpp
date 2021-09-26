// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
#include <bits/stdc++.h>
// #include <cmath>
// #include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>
// #include <vector>

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
int dfs(multimap<int, int> mp[], int row, int val, v(v(bool)) & visited)
{

    int n = visited.size();

    if (row == n - 1)
        return row;

    auto itr = mp[row + 1].find(val);
    if (itr == mp[row + 1].end())
        return row;
    else
    {
        // erase and mark visited
        int cur = itr->second;
        mp[row + 1].erase(itr);
        visited[row + 1][cur] = true;
        return dfs(mp, row + 1, val, visited);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    v(v(int)) A(n + 1, v(int)(m));
    multimap<int, int> mp[n + 1];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
            mp[i].insert({A[i][j], j});
        }

    v(v(bool)) visited(n + 1, v(bool)(m, false));

    multimap<int, int> mp2; // {height, edges}
    int ans = 0;

    for (int j = 0; j < m; j++)
    {
        visited[0][j] = true;
        int h = dfs(mp, 0, A[0][j], visited);
        mp2.insert({h, 0});
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                visited[i][j] = true;
                int h = dfs(mp, i, A[i][j], visited);

                auto itr = mp2.find(i - 1);
                pair<int, int> p;
                p.first = h;
                p.second = itr->second + 1;
                mp2.erase(itr);

                if (p.first == n)
                    ans += max(p.second - 1, 0ll);

                else
                    mp2.insert(p);
            }
        }
    }

    cout << ans << endl;
}
int32_t main()
{
    FastIO;
    int test = 1;
    w(T)
    {
        cout << "Case #" << test++ << ": ";
        solve();
    }
    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //