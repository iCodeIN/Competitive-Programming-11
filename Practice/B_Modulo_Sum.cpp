

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

bool solve(v(int) & A, int n, int current)
{

    // dont choose
    bool ans1 = solve(A, n - 1, current);
    int current_new = (current == -1) ? A[n-1] ? (current + A[n-1]) % A.size();

    bool ans2 = solve(A,n,)
}

void solve()
{
    int n, m;
    cin >> n >> m;

    v(int) A(m);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A[x % m]++;
    }

    bool ans = solve(A, m, -1);
    if (ans)
        cout << "YES";
    else
        cout << "NO";
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //