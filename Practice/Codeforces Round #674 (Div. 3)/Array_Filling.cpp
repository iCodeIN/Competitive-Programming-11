

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
#define debug(x) cout << "{" << #x << " : " << x << "}" << endl;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

int gcd(int a, int b)
{

    while (b > 0)
    {

        int c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int lcm(int a, int b)
{
    if (a > b)
        swap(a, b);
    return a * (b / gcd(a, b));
}

struct Node
{
    int v;
    int m;
};

int solve(v(Node) & A, int m, int n, int LCM)
{

    if (m == 0 or n <= 0)
        return 0;

    int g = gcd(LCM, A[m - 1].m);

    int e = n - (n / (A[m - 1].m / g));

    int ans = (e * A[m - 1].v) + solve(A, m - 1, n - e, lcm(LCM, A[m - 1].m));

    return ans;
}

void solve()
{
    int n, m;

    cin >> n >> m;

    v(Node) A(m);

    for (int i = 0; i < m; i++)
        cin >> A[i].v >> A[i].m;

    sort(A.begin(), A.end(), [](Node a, Node b)
         { return a.v < b.v; });

    int ans = solve(A, m, n, 1);

    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
