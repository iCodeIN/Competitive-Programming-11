
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
    int u;
    int s;
};

void solve()
{
    int n;
    cin >> n;

    v(node) temp(n);
    for (int i = 0; i < n; i++)
        cin >> temp[i].u;
    for (int i = 0; i < n; i++)
        cin >> temp[i].s;

    sort(temp.begin(), temp.end(), [](node &a, node &b) {
        if (a.u != b.u)
            return a.u < b.u;
        return a.s > b.s;
    });

    v(int) comp(n + 1, -1);
    int p = 0;

    for (int i = 0; i < n; i++)
    {
        if (comp[temp[i].u] == -1)
            comp[temp[i].u] = ++p;
        temp[i].u = comp[temp[i].u];
    }

    v(v(int)) A(p);

    for (int i = 0; i < n; i++)
        A[temp[i].u - 1].push_back(temp[i].s);
    int mx_size = 1;
    for (int i = 0; i < p; i++)
    {
        for (int j = 1; j < A[i].size(); j++)
            A[i][j] += A[i][j - 1];
        mx_size = max(mx_size, (int)A[i].size());
    }

    // for (int i = 0; i < p; i++, cout << endl)
    //     for (int j = 0; j < A[i].size(); j++)
    //         cout << A[i][j] << " ";

    for (int i = 1; i <= mx_size; i++)
    {
        int ans = 0;
        for (int j = 0; j < p; j++)
        {
            int idx = ((A[j].size() / i) * i) - 1;
            if (idx >= 0)
                ans += A[j][idx];
        }
        cout << ans << " ";
    }

    for (int i = mx_size + 1; i <= n; i++)
        cout << 0 << " ";

    cout << endl;
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
