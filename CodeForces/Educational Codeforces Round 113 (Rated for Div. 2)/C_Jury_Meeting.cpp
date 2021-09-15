

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
#define mod 998244353ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

const int N = 2 * 1e5;
int f[N + 1];
#define fac f
unsigned long long power(unsigned long long x,
                         int y, int p)
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
                              int p)
{
    return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

int solve(v(int) & A, int n)
{
    if (n == 1)
        return 1;

    if (A[n - 1] == A[n - 2])
        return f[n];
    else if (A[n - 1] - A[n - 2] > 1)
        return 0;
    else
    {
        int i = n - 2;
        int f_ = 0;

        while (i >= 0 and A[i] == A[n - 2])
            i--, f_++;

        int ans = ((nCrModPFermat(n, f_ + 1, mod) * f_) % mod * f[f_]) % mod;

        ans = (ans * (f[n - f_ - 1])) % mod;

        return ans;
    }
}

void solve()
{
    int n;
    cin >> n;

    v(int) A(n);
    for (int &x : A)
        cin >> x;
    sort(all(A));

    int ans = solve(A, n);

    cout << ans << endl;
}

int32_t main()
{
    FastIO;
    f[0] = 1;
    for (int i = 1; i <= N; i++)
        f[i] = (f[i - 1] * i) % mod;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //