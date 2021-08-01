

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
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

int dfs(int root, v(v(int)) & Child, v(int) & Ans)
{
    int ans = 0;

    for (int x : Child[root])
        ans += (1 + dfs(x, Child, Ans));

    return Ans[root] = ans;
}

void solve()
{
    int n;
    cin >> n;

    v(v(int)) Child(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int child = i;
        int parent;
        cin >> parent;
        if (parent != child)
            Child[parent].push_back(child);
    }
    
    v(int) Ans(n + 1);
    dfs(1, Child, Ans);

    for (int i = 1; i <= n; i++)
        cout << Ans[i] << " ";
}

int32_t main()
{
    FastIO;

    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //