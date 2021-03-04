
//------------------------------------------------------------------------------
#include <iostream>
#include <cstring>
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
int dp[55][2][18][18][18];

int g(string &s)
{

    // if (c3 > 17 or c6 > 17 or c9 > 17)
    //     return 0;

    // if (pos == s.length())
    //     return c3 >= 1 and c3 == c6 and c6 == c9;

    // if (dp[pos][tight][c3][c6][c9] != -1)
    //     return dp[pos][tight][c3][c6][c9];

    // int e = (tight) ? s[pos] - '0' : 9;
    // int ans = 0;

    // for (int i = 0; i < e; i++, ans %= mod)
    // {
    //     if (i == 3)
    //         ans += g(s, pos + 1, false, c3 + 1, c6, c9);
    //     else if (i == 6)
    //         ans += g(s, pos + 1, false, c3, c6 + 1, c9);
    //     else
    //         ans += g(s, pos + 1, false, c3, c6, c9);
    // }

    // if (e == 3)
    //     ans += g(s, pos + 1, tight, c3 + 1, c6, c9);
    // else if (e == 6)
    //     ans += g(s, pos + 1, tight, c3, c6 + 1, c9);
    // else if (e == 9)
    //     ans += g(s, pos + 1, tight, c3, c6, c9 + 1);
    // else
    //     ans += g(s, pos + 1, tight, c3, c6, c9);

    // return dp[pos][tight][c3][c6][c9] = ans;

    for (int tight = 0; tight <= 1; tight++)
        for (int c3 = 1; c3 <= 17; c3++)
            for (int c6 = 1; c6 <= 17; c6++)
                for (int c9 = 1; c9 <= 17; c9++)
                    if (c3 == c6 and c6 == c9)
                        dp[s.length()][tight][c3][c6][c9] = 1;

    for (int pos = s.length() - 1; pos >= 0; pos--)
    {

        for (int c3 = 17; c3 >= 0; c3--)
        {
            for (int c6 = 17; c6 >= 0; c6--)
            {
                for (int c9 = 17; c9 >= 0; c9--)
                {
                    for (int tight = 0; tight <= 1; tight++)
                    {
                        int e = (tight) ? s[pos] - '0' : 9;
                        int ans = 0;
                        for (int i = 0; i < e; i++, ans %= mod)
                        {
                            if (i == 3)
                                ans += dp[pos + 1][0][c3 + 1][c6][c9];
                            else if (i == 6)
                                ans += dp[pos + 1][0][c3][c6 + 1][c9];
                            else
                                ans += dp[pos + 1][0][c3][c6][c9];
                        }

                        if (e == 3)
                            ans += dp[pos + 1][tight][c3 + 1][c6][c9];
                        else if (e == 6)
                            ans += dp[pos + 1][tight][c3][c6 + 1][c9];
                        else if (e == 9)
                            ans += dp[pos + 1][tight][c3][c6][c9 + 1];
                        else
                            ans += dp[pos + 1][tight][c3][c6][c9];

                        dp[pos][tight][c3][c6][c9] = ans % mod;
                    }
                }
            }
        }
    }
    return dp[0][1][0][0][0];
}

int f(string &n)
{
    memset(dp, 0, sizeof(dp));
    int ans = g(n);
    return ans;
}

bool check(string &s)
{
    int arr[4] = {0};

    for (int i = 0; i < s.length(); i++)
        if ((s[i] - '0') % 3 == 0)
            arr[(s[i] - '0') / 3]++;

    return arr[1] >= 1 and arr[1] == arr[2] and arr[2] == arr[3];
}
void solve()
{
    string l, r;
    cin >> l >> r;

    int R = (f(r) + check(l)) % mod;
    int L = f(l);

    int ans = (R - L + mod) % mod;

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
