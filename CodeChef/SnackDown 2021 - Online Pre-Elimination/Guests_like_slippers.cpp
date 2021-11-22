

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
#include <map>
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

const int N = 2 * 1e5;
map<int, int> mp[N + 1];

int solve(v(int) & A, int n, int choosen)
{
    if (n == 0)
        return 1;

    if (mp[n].count(choosen))
        return mp[n][choosen];
    
    if (A[n - 1] >= choosen)
    {
        return mp[n][choosen] = solve(A, n - 1, choosen);
    }
    else
    {
        int ans = solve(A, n - 1, choosen);
        ans = (ans + solve(A, n - 1, A[n - 1])) % mod;
        return mp[n][choosen] = ans;
    }
}

void solve()
{
    int n;
    cin >> n;

    v(int) A(n);

    for (int &x : A)
        cin >> x;

    int ans = solve(A, n, 1e6);
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