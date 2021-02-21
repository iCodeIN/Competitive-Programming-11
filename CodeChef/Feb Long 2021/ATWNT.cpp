
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

int pre(int root, v(v(int)) & adjList, int val, v(int) & F)
{

    int ans = 1;
    int children = adjList[root].size();
    if (children > 0)
    {

        for (int i = 0; i < children; ++i)
            ans = Math.lcm(ans, pre(adjList[root][i], adjList, val * children, F));
        F[root] = ans / val;
    }
    else
        F[root] = ans;
    return Math.lcm(val, ans);
}
//------------------------------------------------------------------------------
int solve(int root, int num, v(v(int)) & adjList, v(int) & F)
{
    int children = adjList[root].size();

    if (children > 0)
    {
        if (num % children)
            return num;
        else
        {
            if (num % F[root] == 0)
                return 0;

            int idvTask = num / children;
            int ans = 0;
            for (int i = 0; i < adjList[root].size(); ++i)
                ans += solve(adjList[root][i], idvTask, adjList, F);
            return ans;
        }
    }
    else
    {
        return 0;
    }
}
//------------------------------------------------------------------------------
void addChild(v(v(int)) & adjList, int &p, int &c)
{
    adjList[p].push_back(c);
}
//------------------------------------------------------------------------------
int32_t main()
{
    FastIO;
    int n;
    cin >> n;
    v(int) P(n + 1);
    for (int i = 2; i <= n; ++i)
        cin >> P[i];
    v(v(int)) adjList(n + 1);
    for (int i = 2; i <= n; ++i)
        addChild(adjList, P[i], i);
    v(int) F(n + 1);
    pre(1, adjList, 1, F);
    w(T)
    {
        int root;
        int num;
        cin >> root >> num;
        int ans = solve(root, num, adjList, F);
        cout << ans << endl;
    }

    return 0;
}
//------------------------------------------------------------------------------
