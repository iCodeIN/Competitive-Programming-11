
//------------------------------------------------------------------------------
#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
// #include <cmath>
// #include <algorithm>
// #include <unordered_map>
// #include <map>
// #include <set>
// #include <unordered_set>
//------------------------------------------------------------------------------
using namespace std;
//------------------------------------------------------------------------------
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define v(Type) vector<Type>
#define w(T)  \
    int T;    \
    cin >> T; \
    while (T--)
#define int long long int
#define mod 998244353ll
#define endl "\n"
//------------------------------------------------------------------------------
// Any fucntion can be called using Math.function_name();
//------------------------------------------------------------------------------
class Math
{
public:
    //Returns gcd of two numbers
    int gcd(int a, int b)
    {
        return (a % b == 0) ? b : gcd(b, a % b);
    }

    //Returns lcm of two numbers
    int lcm(int a, int b)
    {
        return a * (b / gcd(a, b));
    }

    // Returns flag array isPrime
    // isPrime[i] = true (if i is Prime)
    // isPrime[i] = false (if i is not Prime)
    vector<bool> *seiveOfEratosthenes(const int N)
    {
        vector<bool> *isPrime = new vector<bool>(N + 1, true);
        (*isPrime)[0] = (*isPrime)[1] = false;
        for (int i = 2; i * i <= N; ++i)
            if ((*isPrime)[i])
                for (int j = i * i; j <= N; j += i)
                    (*isPrime)[j] = false;

        return isPrime;
    }

    //Returns (x ^ n)
    int pow(const int &x, int n)
    {
        if (n == 0)
            return 1;
        int h = pow(x, n >> 1);
        return (n & 1) ? h * h * x : h * h;
    }

    //Returns (x ^ n) % M
    int pow(const int &x, int n, const int &M)
    {
        int p = x;
        int ans = 1;
        while (n > 0)
        {
            if (n & 1)
                ans *= p;
            n >>= 1;
            p *= p;
            if (p >= M)
                p %= M;
            if (ans >= M)
                ans %= M;
        }
        return ans;
    }

    //Returns all Primes <= N
    vector<int> *primesUptoN(const int N)
    {
        vector<bool> *isPrime = seiveOfEratosthenes(N);
        vector<int> *Primes = new vector<int>;
        if (2 <= N)
            (*Primes).push_back(2);
        for (int i = 3; i <= N; i += 2)
            if ((*isPrime)[i])
                (*Primes).push_back(i);
        return Primes;
    }

} Math;
//------------------------------------------------------------------------------

int nCr(const int &n, const int &r, const v(int) & fact, const v(int) & invfact)
{
    if (r > n or r < 0)
        return 0;
    if (r == 0)
        return 1;

    if (n <= 0)
        return 0;
    int ans = fact[n] * invfact[r];
    if (ans > mod)
        ans %= mod;
    ans *= invfact[n - r];
    if (ans > mod)
        ans %= mod;
    return ans;
}

void findAns(v(int) & dp, const v(int) & setBits, const int &len, const v(int) & fact, const v(int) & invfact, int &n)
{
    v(int) temp(32, 0);
    for (int i = 0; i < 32; ++i)
    {
        int start = max(1ll, len - (n - setBits[i]));
        if (!(start & 1))
            ++start;
        int end = min(setBits[i], len);
        for (int set = start; set <= end; set += 2)
            temp[i] = (temp[i] + (nCr(setBits[i], set, fact, invfact) * nCr(n - setBits[i], len - set, fact, invfact)) % mod) % mod;
    }
    int ans = 0;
    for (int i = 0; i < 31; ++i)
        ans = (ans + (temp[i] * (1 << i)) % mod) % mod;

    dp[len] = ans;
}

void solve()
{
    int n;
    cin >> n;
    v(int) A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    v(int) setBits(32, 0);
    for (int j = 0; j < 32; ++j)
        for (int i = 0; i < n; ++i)
            if (A[i] & (1 << j))
                ++setBits[j];

    v(int) naturalNumInv(n + 1), fact(n + 1), invfact(n + 1);
    fact[0] = fact[1] = invfact[0] = invfact[1] = naturalNumInv[0] = naturalNumInv[1] = 1;
    for (int i = 2; i <= n; ++i)
        naturalNumInv[i] = (naturalNumInv[mod % i] * (mod - mod / i)) % mod;
    for (int i = 2; i <= n; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        invfact[i] = (naturalNumInv[i] * invfact[i - 1]) % mod;
    }

    int q;
    cin >> q;
    v(int) Q(q);
    int mxQ = 0;
    for (int i = 0; i < q; ++i)
    {
        cin >> Q[i];
        mxQ = max(Q[i], mxQ);
    }
    v(int) dp(mxQ + 1, 0);
    for (int len = 1; len <= mxQ; ++len)
        findAns(dp, setBits, len, fact, invfact, n);
    for (int len = 2; len <= mxQ; ++len)
        dp[len] = (dp[len] + dp[len - 1]) % mod;

    for (int i = 0; i < q; ++i)
        cout << dp[Q[i]] << endl;
}
//------------------------------------------------------------------------------
int32_t main()
{
    FastIO;

    solve();

    return 0;
}
//------------------------------------------------------------------------------
