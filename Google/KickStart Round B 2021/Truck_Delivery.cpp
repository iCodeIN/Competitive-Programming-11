
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

struct node
{
    int v, maxLoad, toll;
};

struct item
{
    bool found = false;
    int gcd = 0;
};

item dfs(int x, int load, v(v(node)) & A, v(bool) & visited)
{
    visited[x] = true;
    item ans;
    for (int i = 0; i < A[x].size(); i++)
    {

        if (A[x][i].v == 0)
        {
            ans.found = true;
            if (A[x][i].maxLoad <= load)
            {
                ans.gcd = (ans.gcd == 0) ? A[x][i].toll : Math.gcd(A[x][i].toll, ans.gcd);
            }
            return ans;
        }

        if (!visited[A[x][i].v])
        {
            ans = dfs(A[x][i].v, load, A, visited);
            if (ans.found == true)
            {
                if (A[x][i].maxLoad <= load)
                {
                    ans.gcd = (ans.gcd == 0) ? A[x][i].toll : Math.gcd(A[x][i].toll, ans.gcd);
                }
                return ans;
            }
        }
    }
    return ans;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    v(v(node)) A(n);

    for (int i = 0; i < n - 1; i++)
    {
        int x, y, load, toll;
        cin >> x >> y >> load >> toll;
        x--, y--;
        A[x].push_back({y, load, toll});
        A[y].push_back({x, load, toll});
    }

    while (q--)
    {
        int s, load;
        cin >> s >> load;
        s--;
        v(bool) visited(n, false);
        auto ans = dfs(s, load, A, visited);
        cout << ans.gcd << " ";
    }
    cout << endl;
}
//------------------------------------------------------------------------------
int32_t main()
{
    FastIO;
    int test = 1;
    w(T)
    {
        cout << "Case #" << test++ << ": ";
        solve();
    }
    return 0;
}
//------------------------------------------------------------------------------
