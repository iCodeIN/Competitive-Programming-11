
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

struct SegTree
{
    v(int) t;
    int size;

    int init = INT64_MAX;

    int f(int &a, int &b)
    {
        return min(a, b);
    }

    SegTree(v(int) & A)
    {
        size = 1;
        int n = A.size();
        while (size < n)
            size *= 2;
        t.assign(2 * size, INT32_MAX);
        build(A, 0, 0, size);
    }

    void build(v(int) & A, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < A.size())
                t[x] = A[lx];
            return;
        }

        int m = (lx + rx) >> 1;

        build(A, 2 * x + 1, lx, m);
        build(A, 2 * x + 2, m, rx);

        t[x] = f(t[2 * x + 1], t[2 * x + 2]);
    }

    void set(int &i, int &v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            t[x] = v;
            return;
        }

        int m = (lx + rx) >> 1;

        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);

        t[x] = f(t[2 * x + 1], t[2 * x + 2]);
    }

    int query(int &l, int &r, int x, int lx, int rx)
    {
        if (lx >= r or l >= rx)
            return init;

        if (l <= lx and rx <= r)
            return t[x];

        int m = (lx + rx) >> 1;

        int ans1 = query(l, r, 2 * x + 1, lx, m);
        int ans2 = query(l, r, 2 * x + 2, m, rx);

        return f(ans1, ans2);
    }

    void set(int &i, int &v)
    {
        set(i, v, 0, 0, size);
    }

    int query(int &l, int &r)
    {
        return query(l, r, 0, 0, size);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    v(int) A(n);
    for (int &x : A)
        cin >> x;

    SegTree st(A);

    while (q--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r) << endl;
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
