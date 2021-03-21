
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
#define mod 1000000000ll
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
int n, k;
v(v(int)) F1, Constants;

v(v(int)) multiply(v(v(int)) A, v(v(int)) B, int r1, int c1, int r2, int c2)
{
    v(v(int)) C(r1, v(int)(c2, 0));
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k1 = 0; k1 < c1; k1++)
                C[i][j] = (C[i][j] + (A[i][k1] * B[k1][j]) % mod) % mod;

    return C;
}

v(v(int)) pow(v(v(int)) A, int n)
{

    if (n == 0)
    {
        v(v(int)) I(k, v(int)(k));
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                I[i][j] = (i == j);
        return I;
    }
    if (n & 1)
        return multiply(pow(A, n - 1), A, k, k, k, k);
    else
    {
        v(v(int)) half = pow(A, n >> 1);
        return multiply(half, half, k, k, k, k);
    }
}

void solve()
{
    cin >> k;
    F1.resize(k);
    Constants.resize(k);
    for (int i = 0; i < k; i++)
        F1[i].resize(1), Constants[i].resize(1);

    for (int i = 0; i < k; i++)
        cin >> F1[i][0];

    for (int i = 0; i < k; i++)
        cin >> Constants[i][0];

    cin >> n;
    int ans = 0;

    v(v(int)) T(k, v(int)(k, 0));

    for (int i = 0; i < k - 1; i++)
        for (int j = 0; j < k; j++)
            if (i == j)
                T[i][j + 1] = 1;

    for (int j = 0; j < k; j++)
        T[k - 1][j] = Constants[k - j - 1][0];

    if (n <= k)
        ans = F1[n - 1][0];
    else
    {
        v(v(int)) T_ = pow(T, n - k);

        v(v(int)) Ans = multiply(T_, F1, k, k, k, 1ll);

        ans = Ans[k - 1][0];
    }
    cout << ans << endl;
    F1.clear();
    Constants.clear();
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