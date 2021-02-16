
//------------------------------------------------------------------------------
#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
// #include <cmath>
#include <algorithm>
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
#define pii pair<int, int>
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

struct triplet
{
    int w;
    int p;
    int j;
};
bool comp(triplet &a, triplet &b)
{
    if (a.p == b.p)
        return a.w > b.w;
    return a.p < b.p;
}

bool isSorted(v(triplet) & F)
{
    int n = F.size();
    for (int i = 0; i < n - 1; ++i)
        if (F[i].w > F[i + 1].w)
            return false;
    return true;
}

//------------------------------------------------------------------------------
void solve()
{
    int n;
    cin >> n;

    v(triplet) F(n); //(Weight, Position, Jump)

    for (int i = 0; i < n; ++i)
    {
        cin >> F[i].w;
        F[i].p = i + 1;
    }
    for (int i = 0; i < n; ++i)
        cin >> F[i].j;

    int ans = 0;

    while (!isSorted(F))
    {
        for (int i = 0; i < n - 1; ++i)
        {
            if (F[i].w > F[i + 1].w)
            {
                F[i].p += F[i].j;
                ++ans;
                sort(F.begin(), F.end(), comp);
            }
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
