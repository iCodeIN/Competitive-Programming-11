
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

v(bool) isPrime = *Math.seiveOfEratosthenes(100);

static int dp[11][2][100][4001];
int solve(string &s, int pos, bool tight, int sum, int rem, int &k)
{
    if (pos == s.length())
        return isPrime[sum] and rem == 0;

    if (dp[pos][tight][sum][rem] != -1)
        return dp[pos][tight][sum][rem];

    int ub = (tight) ? s[pos] - '0' : 9;
    int ans = 0;
    for (int i = 0; i <= ub; i++)
        ans += solve(s, pos + 1, tight and (i == ub), sum + i, (rem * 10 + i) % k, k);

    return dp[pos][tight][sum][rem] = ans;
}
int f(string &s, int k)
{
    for (int pos = 0; pos < s.length(); pos++)
        for (int tight = 0; tight <= 1; tight++)
            for (int sum = 0; sum <= 9 * s.length(); sum++)
                for (int rem = 0; rem < k; rem++)
                    dp[pos][tight][sum][rem] = -1;
    int ans = solve(s, 0, 1, 0, 0, k);
    return ans;
}

bool check(int x)
{
    int sum = 0;
    while (x)
    {
        sum += x % 10;
        x /= 10;
    }
    return isPrime[sum];
}

void solve()
{
    int a, b;
    cin >> a >> b;

    a--;
    string r = to_string(b);
    string l = to_string(a);

    int k;
    cin >> k;

    int ans = 0;
    if (k <= 4000)
        ans = f(r, k) - f(l, k);
    else
    {
        a++;
        int s = (a % k == 0) ? a : k + a - a % k;
        // cout << s << endl;
        while (s <= b)
        {
            ans += check(s);
            s += k;
        }
    }
    cout << ans << endl;
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
