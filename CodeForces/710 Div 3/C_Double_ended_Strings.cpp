
//------------------------------------------------------------------------------
// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>
// #include <cmath>
// #include <algorithm>
// #include <unordered_map>
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
int dp[21][21][21][21];
int solve(string &a, string &b, int s1, int e1, int s2, int e2)
{
    int l1 = e1 - s1 + 1;
    int l2 = e2 - s2 + 1;

    l1 = max(l1, 0ll);
    l2 = max(l2, 0ll);

    if (l1 == 0)
        return l2;

    if (l2 == 0)
        return l1;

    if (a.substr(s1, l1) == b.substr(s2, l2))
        return 0;
    if (dp[s1][e1][s2][e2] != -1)
    {
        return dp[s1][e1][s2][e2];
    }
    int ans1 = (s1 <= e1) ? solve(a, b, s1 + 1, e1, s2, e2) : INT32_MAX;
    int ans2 = (s1 <= e1) ? solve(a, b, s1, e1 - 1, s2, e2) : INT32_MAX;
    int ans3 = (s2 <= e2) ? solve(a, b, s1, e1, s2 + 1, e2) : INT32_MAX;
    int ans4 = (s2 <= e2) ? solve(a, b, s1, e1, s2, e2 - 1) : INT32_MAX;

    return dp[s1][e1][s2][e2] = min(ans1, min(ans2, min(ans3, ans4))) + 1;
}

void solve()
{
    string a, b;
    cin >> a >> b;
    int m = a.length();
    int n = b.length();
    memset(dp, -1, sizeof(dp));
    int ans = solve(a, b, 0, m - 1, 0, n - 1);

    cout << ans << endl;
}
//------------------------------------------------------------------------------
int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}
//------------------------------------------------------------------------------
