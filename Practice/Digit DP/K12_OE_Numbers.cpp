
//------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cstring>
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
int solve(string s, int pos, bool tight, int sum_odd, int sum_even, int dp[10][2][45][45])
{
    if (pos == s.length())
        return sum_odd < sum_even;

    if (dp[pos][tight][sum_odd][sum_even] != -1)
        return dp[pos][tight][sum_odd][sum_even];
    
    int e = (tight) ? s[pos] - '0' : 9;

    int ans = 0;
    for (int i = 0; i <= e - 1; i++)
        if (i & 1)
            ans += solve(s, pos + 1, false, sum_odd + i, sum_even, dp);
        else
            ans += solve(s, pos + 1, false, sum_odd, sum_even + i, dp);

    if (e & 1)
        ans += solve(s, pos + 1, tight, sum_odd + e, sum_even, dp);
    else
        ans += solve(s, pos + 1, tight, sum_odd, sum_even + e, dp);

    return dp[pos][tight][sum_odd][sum_even] = ans;
}

int solver(string s)
{
    int dp[10][2][45][45];
    memset(dp, -1, sizeof(dp));
    return solve(s, 0, 1, 0, 0, dp);
}

void solve()
{
    int a, b;
    cin >> a >> b;

    int ans1 = solver(to_string(b));
    int ans2 = (a == 1) ? 0 : solver(to_string(a - 1));

    cout << ans1 - ans2 << endl;
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
