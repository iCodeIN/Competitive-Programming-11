
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
void solve()
{
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    v(int) A(n);
    v(int) Ans(n, 0);
    for (int i = 0; i < n; i++)
        A[i] = i + 1;
    int sum1 = 0, sum2 = 0;
    int window = r - l + 1;

    for (int i = 0; i < window; i++)
        sum1 += A[i];
    for (int i = n - 1, j = 0; j < window; j++, i--)
        sum2 += A[i];

    bool ans = sum1 <= s and s <= sum2;

    if (ans)
    {
        int dp[n + 1][s + 1][window + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= s; j++)
                for (int k = 0; k <= window; k++)
                    if (i == 0)
                        dp[i][j][k] = true;
                    else if (j == 0 or k == 0)
                        dp[i][j][k] = false;
                    else
                    {
                        if (A[i - 1] <= s)
                            dp[i][j][k] = dp[i - 1][j - A[i - 1]][k] or dp[i - 1][j][k];
                        else
                            dp[i][j][k] = dp[i - 1][j][k];
                    }
        
    }
    else
        cout << -1;
    cout << endl;
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
