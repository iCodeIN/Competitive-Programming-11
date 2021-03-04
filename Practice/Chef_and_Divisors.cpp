
//------------------------------------------------------------------------------
#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
#include <cmath>
// #include <algorithm>
#include <unordered_map>
// #include <map>
// #include <set>
// #include <unordered_set>
//------------------------------------------------------------------------------
using namespace std;
//------------------------------------------------------------------------------
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define v(Type) vector<Type>
#define w(T)  \
    int T;    \
    cin >> T; \
    while (T--)
#define int long long int
#define mod 1000000007ll
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

    // Returns smallest prime factor of all numbers <= n
    vector<int> *spf(const int n)
    {
        vector<int> *spf = new vector<int>(n + 1);
        for (int i = 2; i <= n; i++)
            (*spf)[i] = i;
        for (int i = 2; i * i <= n; ++i)
            if ((*spf)[i] == i)
                for (int j = i * i; j <= n; j += i)
                    if ((*spf)[j] == j)
                        (*spf)[j] = i;
        return spf;
    }

    //Returns (x ^ n)
    int pow(const int &x, int n)
    {
        if (n == 0)
            return 1;
        int h = pow(x, n / 2);
        return (n & 1) ? h * h * x : h * h;
    }

    //Returns (x ^ n) % M
    int pow(const int &x, int n, const int &M)
    {
        if (n == 0)
            return 1;
        int h = pow(x, n / 2) % M;
        return (n & 1) ? (h * h * x) % M : (h * h) % M;
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
v(int) spf = *Math.spf(1e6);
void solve()
{
    int n;
    cin >> n;

    int ans = 1;

    unordered_map<int, int> mp;

    while (n != 1)
    {
        mp[spf[n]]++;

        n /= spf[n];
    }

    int odd = 0;
    int even = 0;
    int zero = 0;

    for (auto &x : mp)
    {
        x.second %= 3;

        if (x.second == 0)
            zero++;
        else if (x.second == 1)
            odd++;
        else if (x.second == 2)
            even++;
    }

    if (odd % 2 == 0 and even % 2 == 0)
        ans = 1;
    else if (odd % 2 != 0 and even % 2 == 0)
    {
        if (zero)
            ans = 1;
        else
            ans = 2;
    }
    else if (odd % 2 == 0 and even % 2 != 0)
    {
        if (even == 1 and odd == 0)
        {
            if (zero > 1)
                ans = 1;
            else if (zero == 1)
                ans = 2;
            else
                ans = 3;
        }
        else
            ans = 1;
    }
    else
    {
        if (zero)
            ans = 1;
        else
            ans = 2;
    }

    cout << ans << endl;
}
//------------------------------------------------------------------------------
int32_t main()
{
    FastIO;

    w(T)
    {
        solve();
    }

    return 0;
}
//------------------------------------------------------------------------------


