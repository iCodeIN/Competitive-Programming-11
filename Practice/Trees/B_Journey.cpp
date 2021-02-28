
//------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <iomanip>
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
#define mod 1000000007ll
#define ll long long int
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

void dfs(const int &v, v(v(int)) & Adj, v(ll) & Prob, const ll &prev, const int l, v(int) & Len)
{
    Len[v] = l;
    Prob[v] = prev;
    ll c = (v == 1) ? Adj[v].size() : Adj[v].size() - 1;
    for (int i = 0; i < Adj[v].size(); i++)
        if (Prob[Adj[v][i]] == -1)
            dfs(Adj[v][i], Adj, Prob, c * prev, l + 1, Len);
}

void solve()
{
    int n;
    cin >> n;
    v(v(int)) Adj(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    v(ll) Prob(n + 1, -1);
    v(int) Len(n + 1);
    dfs(1, Adj, Prob, 1, 0ll, Len);

    long double ans = 0;

    for (int i = 2; i <= n; i++)
        if (Adj[i].size() == 1 and Prob[i])
            ans += ((1.0 * Len[i]) / Prob[i]);

    cout << std::setprecision(15) << fixed << ans << endl;
}
//------------------------------------------------------------------------------
int32_t main()
{
    FastIO;

    solve();

    return 0;
}
//------------------------------------------------------------------------------
