

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
int dfs(int cur, v(bool) & visited, v(int) & T, v(v(int)) & A)
{

    visited[cur] = true;

    int ans = T[cur - 1];

    for (int x : A[cur - 1])
        if (!visited[x])
            ans += dfs(x, visited, T, A);

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    v(bool) visited(n + 1, false);

    v(v(int)) A(n);

    v(int) T(n);
    for (int i = 0; i < n; i++)
    {
        cin >> T[i];
        int size;
        cin >> size;
        A[i].resize(size);
        for (int &x : A[i])
            cin >> x;
    }

    int ans = dfs(n, visited, T, A);

    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //