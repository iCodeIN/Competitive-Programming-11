

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
int pow(int x, int n, int m)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans = (ans * x) % m;

        n >>= 1;
        x = (x * x) % m;
    }
    return ans;
}

bool solve()
{
    int x, a, n, c;
    cin >> x >> a >> n >> c;

    if (x == 0 and a == 0 and n == 0 and c == 0)
        return false;

    int f = pow(a, n, c);
    int t1 = (f * x) % c;
    int t2 = (a * (f - 1) * pow(a - 1, c - 2, c)) % c;
    int ans = (t1 - t2 + c) % c;

    cout << ans << endl;
    return true;
}

int32_t main()
{
    FastIO;
    while (solve())
    {
        // do nothing
    }

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //