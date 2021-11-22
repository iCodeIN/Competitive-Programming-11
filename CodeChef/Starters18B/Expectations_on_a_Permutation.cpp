

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
#include <bits/stdc++.h>
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
        if (n & 1ll)
        {
            ans = (ans * x) % m;
        }

        n >>= 1ll;

        x = (x * x) % m;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;

    int num = (3 * (n * n) % mod) % mod;
    num -= n;
    num -= 2;
    num += mod;
    num %= mod;
    num = (num * (n + 1)) % mod;
    // cout << num << endl;
    int den = 12;

    int x = pow(den, mod - 2, mod);

    cout << (num * x) % mod << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //