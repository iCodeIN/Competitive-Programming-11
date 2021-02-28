
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

void reverse(v(int) & A, int s, int e)
{
    while (s < e)
    {
        A[s] = e + 1;
        A[e] = s + 1;
        s++, e--;
    }
}
//------------------------------------------------------------------------------
bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}

void solve(int p)
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++)
        cin >> queries[i].first >> queries[i].second;

    sort(queries.begin(), queries.end(), comp);
    v(int) Ans(n + 1, 0);
    for (int i = 0; i < q; i++)
        Ans[queries[i].second] -= 1, Ans[queries[i].first - 1] += 1;

    for (int i = 1; i < n; i++)
        Ans[i] += Ans[i - 1];

    int x = (p == 0) ? 1 : n;
    if (p == 0)
        for (int i = 0; i < n; i++)
            if (Ans[i])
                Ans[i] = i + 1;
            else
                Ans[i] = x;
    else
    {
        v(int) temp(n, 0);
        for (int i = 1; i < q; i++)
            if (queries[i - 1].second < queries[i].first and Ans[i - 1] == 1)
                reverse(temp, queries[i].first, queries[i].second);
        for (int i = 0; i < n; i++)
            if (Ans[i])
                Ans[i] = i + 1;
            else
                Ans[i] = x;
        for (int i = 0; i < n; i++)
            if (temp[i] != 0)
                Ans[i] = temp[i];
    }
    for (int i = 0; i < n; i++)
        cout << Ans[i] << " ";
    cout << endl;
}
//------------------------------------------------------------------------------
int32_t main()
{
    FastIO;

    int t;
    cin >> t;
    int p;
    cin >> p;
    while (t--)
        solve(p);

    return 0;
}
//------------------------------------------------------------------------------
