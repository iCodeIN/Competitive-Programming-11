
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
struct Node
{
    int Max;
    int Min;
};

int f(int a, int b)
{
    return a * b + abs(a - b);
}
void solve()
{
    int n;
    cin >> n;
    v(int) A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    v(Node) Prefix(n);
    Prefix[0].Max = Prefix[0].Min = A[0];
    for (int i = 1; i <= n - 1; i++)
    {
        Prefix[i].Max = max(A[i], Prefix[i - 1].Max);
        Prefix[i].Min = min(A[i], Prefix[i - 1].Min);
    }
    v(Node) Suffix(n);
    Suffix[n - 1].Min = Suffix[n - 1].Max = A[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        Suffix[i].Max = max(A[i], Suffix[i + 1].Max);
        Suffix[i].Min = min(A[i], Suffix[i + 1].Min);
    }
    int ans = INT64_MIN;
    for (int b = 0; b <= n - 1; b++)
    {
        int a;

        if (b > 0)
        {
            ans = max(ans, f(A[b], Prefix[b - 1].Min));
            ans = max(ans, f(A[b], Prefix[b - 1].Max));
        }

        if (b < n - 1)
        {
            ans = max(ans, f(A[b], Suffix[b + 1].Min));
            ans = max(ans, f(A[b], Suffix[b + 1].Max));
        }
    }
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
