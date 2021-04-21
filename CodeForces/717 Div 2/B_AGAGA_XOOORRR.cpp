
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

int search(int x, v(int) & A, int i)
{
    int cur = 0;

    while (i < A.size())
    {
        cur ^= A[i];
        i++;
        if (cur == x)
            return i;
    }
    return -1;
}

void solve()
{
    int n;
    cin >> n;
    v(int) A;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x)
            A.push_back(x);
    }
    n = A.size();
    bool ans = (n == 0);

    if (ans == false)
    {
        v(int) pre(n);
        pre[0] = A[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] ^ A[i];

        int cur = 0;

        int j = 1;
        for (int w_size = 1; w_size <= n - 1; w_size++)
        {
            j = w_size;
            int x_or = pre[w_size - 1];
            while (j != -1 and j != n)
                j = search(x_or, A, j);
            if (j == n)
                break;
        }
        ans = (j != -1);
    }

    if (ans)
        cout << "YES";
    else
        cout << "NO";

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
