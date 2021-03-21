
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
        int ans = 1;
        int temp = x;
        while (n)
        {
            if (n & 1)
                ans = (ans * temp) % M;
            temp = (temp * temp) % M;
            n >>= 1;
        }
        return ans;
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
void dfs(int vertex, v(v(int)) & adj, v(bool) & visited, v(int) & Ans, int d, int prev = 1)
{
    // cout << vertex << "->" << prev << endl;
    visited[vertex] = true;
    Ans[vertex] = (Ans[vertex] + Math.pow(prev, mod - 2, mod)) % mod;

    if (d == 0)
        return;
    int unvisited = 0;

    for (int i = 0; i < adj[vertex].size(); i++)
        if (visited[adj[vertex][i]] == false)
            unvisited++;

    for (int i = 0; i < adj[vertex].size(); i++)
        if (visited[adj[vertex][i]] == false)
            dfs(adj[vertex][i], adj, visited, Ans, d - 1, (prev * unvisited) % mod);
}
void solve()
{
    int n, q;
    cin >> n >> q;
    v(v(int)) adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int last = 0;
    v(int) Ans(n + 1, 0);
    while (q--)
    {
        int qType;
        cin >> qType;

        if (qType == 1)
        {
            int a, b;
            cin >> a >> b;
            int u = (last + a) % n + 1;
            int d = (last + b) % n + 1;

            v(bool) visited(n + 1, false);
            dfs(u, adj, visited, Ans, d);
        }
        else
        {
            int a;
            cin >> a;
            int u = (last + a) % n + 1;
            cout << Ans[u] << endl;
            last = Ans[u];
        }
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
