

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

// #define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
const int N = 1e6 + 1;
vector<int64_t> phi(N + 1);

void phi_1_to_n(int n)
{
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
int64_t f(int n)
{

    int64_t ans = 0;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int f1 = i;
            int f2 = n / i;

            ans += phi[(n + f1) / f1];
            if (f1 != f2)
            {
                ans += phi[(n + f2) / f2];
            }
        }
    }
    return 2ll * ans;
}

void solve()
{
    int n;
    cin >> n;

    cout << f(n) << endl;
}

int32_t main()
{
    FastIO;
    phi_1_to_n(N);
    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //