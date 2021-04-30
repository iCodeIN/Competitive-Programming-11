
//------------------------------------------------------------------------------
#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
// #include <cmath>
#include <algorithm>
// #include <unordered_map>
#include <map>
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

struct node
{
    int val;
    int u;
};

void dfs(int x, v(bool) & visited, v(v(int)) & adj, v(int) & sp, map<int, int> &mp, int dist = 0)
{
    visited[x] = true;

    if (sp[x])
    {
        mp[x] = dist;
    }

    for (int i = 0; i < adj[x].size(); i++)
    {
        if (visited[adj[x][i]] == false)
            dfs(adj[x][i], visited, adj, sp, mp, dist + 1);
    }
}

node solve(map<int, int> &mp1, map<int, int> &mp2)
{
    node ans;
    ans.val = INT64_MIN;
    for (auto &x : mp1)
    {
        int temp = x.second - mp2[x.first];

        if (temp > ans.val)
        {
            ans.val = temp;
            ans.u = x.first;
        }
    }
    return ans;
}

bool check(v(v(int)) & adj)
{
    for (int i = 1; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
            if (adj[i][j] != i - 1 and adj[i][j] != i + 1)
            {
                // cout << adj[i][j] << " " << i << " ";
                // cout << "not equal\n";
                return false;
            }
    }
    return true;
}

int bs(v(int) & A, int x)
{
    // max m <= x

    int l = -1;
    int r = A.size();

    while (r - l > 1)
    {
        int m = (l + r) / 2;

        if (A[m] <= x)
            l = m;
        else
            r = m;
    }
    return l;
}

int bs2(v(int) & A, int x)
{
    // min m >= x

    int l = -1;
    int r = A.size();

    while (r - l > 1)
    {
        int m = (l + r) / 2;

        if (A[m] >= x)
            r = m;
        else
            l = m;
    }
    return r;
}

node solve(int a, int b, v(int) & sp)
{
    // if (a > b)
    //     swap(a, b);
    int m = min(a, b);
    int M = max(a, b);
    int idx = (a == m) ? (bs(sp, b)) : bs(sp, b);
    node ans;
    ans.val = INT64_MIN;

    int o1 = INT64_MIN;
    int u1 = sp[0];

    if (sp[0] < m)
        o1 = a - b;

    else if (m <= sp[0] and sp[0] <= M)
    {
        o1 = 2 * sp[0] - (a + b);
        if (a == M)
            o1 = -o1;
    }
    else
        o1 = b - a;

    int o2 = (idx != -1 and idx != sp.size()) ? 2 * sp[idx] - (a + b) : INT64_MIN;
    int u2 = (idx != -1 and idx != sp.size()) ? sp[idx] : -1;

    if (a == M and idx != sp.size() and idx != -1)
    {
        o2 = (a + b) - 2 * sp[idx];
    }

    int o3 = INT64_MIN;
    int u3 = sp[sp.size() - 1];

    if (sp[sp.size() - 1] < m)
        o3 = a - b;

    else if (m <= sp[sp.size() - 1] and sp[sp.size() - 1] <= M)
    {
        o3 = 2 * sp[sp.size() - 1] - (a + b);
        if (a == M)
            o3 = -o3;
    }
    else
        o3 = b - a;
    // cout << b << " : " << o1 << " " << o2 << " " << o3 << endl;
    ans.val = max(o1, max(o2, o3));

    if (o1 == ans.val)
        ans.u = u1;
    else if (o2 == ans.val and u2 != -1)
        ans.u = u2;
    else
        ans.u = u3;
    return ans;
}

void solve()

{
    int n, k, a;
    cin >> n >> k >> a;

    v(int) sp(n + 1, false);
    v(int) sp2(k);
    for (int i = 0; i < k; i++)
    {
        cin >> sp2[i];
        sp[sp2[i]] = true;
    }

    v(v(int)) adj(n + 1);

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u != v)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    bool ok = check(adj);
    // ok = false;
    if (ok)
    {
        // cout << "ok";
        sort(sp2.begin(), sp2.end());
        v(node) Ans(n + 1);
        for (int i = 1; i <= n; i++)
            Ans[i] = solve(a, i, sp2);
        for (int i = 1; i <= n; i++)
            cout << Ans[i].val << " ";
        cout << endl;
        for (int i = 1; i <= n; i++)
            cout << Ans[i].u << " ";

        cout << endl;
    }
    else
    {
        v(bool) visited(n + 1, false);
        map<int, int> mp;
        dfs(a, visited, adj, sp, mp, 0);

        v(node) Ans(n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (i != a)
            {
                map<int, int> mp2;
                v(bool) visited(n + 1, false);
                dfs(i, visited, adj, sp, mp2);
                Ans[i] = solve(mp, mp2);
            }
            else
                Ans[i] = solve(mp, mp);
        }

        for (int i = 1; i <= n; i++)
            cout << Ans[i].val << " ";
        cout << endl;
        for (int i = 1; i <= n; i++)
            cout << Ans[i].u << " ";

        cout << endl;
    }
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
