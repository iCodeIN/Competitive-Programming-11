
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
int solve(string &s, int pos, bool tight, int sum, int dp[11][2][101])
{
    if (pos == s.length())
        return sum;

    if (dp[pos][tight][sum] != -1)
        return dp[pos][tight][sum];
    
    int e = (tight) ? s[pos] - '0' : 9;
    int ans = 0;
    for (int i = 0; i <= e - 1; i++)
        ans += solve(s, pos + 1, false, sum + i, dp);

    ans += solve(s, pos + 1, tight, sum + e, dp);

    return dp[pos][tight][sum] = ans;
}

int solve1(string s, int pos, bool tight)
{
    int dp[11][2][101];
    memset(dp, -1, sizeof(dp));
    return solve(s, 0, 1, 0, dp);
}

void solve()
{
    int a, b;
    cin >> a >> b;

    while (a != -1 and b != -1)
    {
        int ans1 = solve1(to_string(b), 0, 1);
        int ans2 = (a == 0) ? 0 : solve1(to_string(a - 1), 0, 1);
        int ans = ans1 - ans2;

        cout << ans << endl;

        cin >> a >> b;
    }
}
//------------------------------------------------------------------------------
int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}
//------------------------------------------------------------------------------
