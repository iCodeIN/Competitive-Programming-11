
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
int solve(string &s, int n, int prev, int &x, int &y, v(v(int)) & dp)
{
    if (n == 0)
        return 0;
    if (dp[n][prev] != -1)
        return dp[n][prev];
    int ans = 0;
    if (s[n - 1] == 2)
    {

        int ans1 = solve(s, n - 1, 0, x, y, dp);
        int ans2 = solve(s, n - 1, 1, x, y, dp);

        if (prev == 0)
            ans2 += y;
        else if (prev == 1)
            ans1 += x;
        ans = min(ans1, ans2);
    }
    else
    {
        ans = solve(s, n - 1, s[n - 1], x, y, dp);
        if (prev == 0 and s[n - 1] == 1)
            ans += y;
        else if (prev == 1 and s[n - 1] == 0)
            ans += x;
    }
    return dp[n][prev] = ans;
}

void solve()
{
    int x, y;
    string s;
    cin >> x >> y >> s;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == 'C')
            s[i] = 0;
        else if (s[i] == 'J')
            s[i] = 1;
        else
            s[i] = 2;
    v(v(int)) dp(s.length() + 1, v(int)(3, -1));
    int ans = solve(s, s.length(), 2, x, y, dp);
    cout << ans << endl;
}
//------------------------------------------------------------------------------
int32_t main()
{
    FastIO;
    int test = 1;
    w(T)
    {
        cout << "Case #" << test++ << ": ";
        solve();
    }
    return 0;
}
//------------------------------------------------------------------------------
