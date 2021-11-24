

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
unsigned long long pow(unsigned long long x,
                       int y, int p = mod)
{
    unsigned long long res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {

        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n,
                              int p = mod)
{
    return pow(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
unsigned long long fac[200001];
unsigned long long nCr(unsigned long long n,
                       int r, int p = mod)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

int f(map<int, int> &mp)
{
    int x1 = 0;
    int x2 = 0;

    int ans = 0;

    for (auto itr : mp)
    {
        if (itr.first % 4)
            x1 += itr.second;
        else
            x2 += itr.second;
    }
    cout << x1 << " " << x2 << endl;
    if (x1)
    {
        ans = ((pow(2, x1 - 1) - 1 + mod) % mod * (pow(2, x2))) % mod;
    }
    cout << ans << " ";
    if (x2)
    {
        ans = (ans + pow(2, x2) - 1 - x2 + mod) % mod;
    }
    cout << ans << endl;
    return ans;
}

void solve()
{
    int n;
    cin >> n;

    map<int, int> mp;

    int odd = 0;
    int even = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x % 2)
            odd++;
        else
            mp[x]++, even++;
    }

    int ans1 = ((pow(2, odd) - 1 + mod) % mod) * (pow(2, even)) % mod;

    int ans2 = f(mp);
    cout << ans1 << " " << ans2 << " " << endl;
    int ans = (ans1 + ans2) % mod;
    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    fac[0] = 1;
    for (int i = 1; i <= 200000; i++)
        fac[i] = (fac[i - 1] * i) % mod;
    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //