
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
struct Node
{
    int v = INT32_MAX, c = 0;
};

class SegmentTree
{
private:
    v(Node) tree;
    int size;
    //
    Node neutralValue;

    Node merge(Node &a, Node &b)
    {
        Node ans;
        if (a.m == b.m)
        {
            ans.m = a.m;
        }
        return ans;
    }

    void build(v(int) & A, int x, int lx, int rx)
    {

        if (rx - lx == 1)
        {
            if (lx < (int)A.size())
            {
                Node temp;
                //
                tree[x] = temp;
            }
            return;
        }

        int mx = (lx + rx) >> 1ll;
        build(A, (x << 1ll) + 1ll, lx, mx);
        build(A, (x << 1ll) + 2ll, mx, rx);
        tree[x] = merge(tree[(x << 1ll) + 1ll], tree[(x << 1ll) + 2ll]);
    }

    void update(int idx, int val, int x, int lx, int rx)
    {

        if (rx - lx == 1)
        {
            Node temp;
            //
            tree[x] = temp;
            return;
        }

        int mx = (lx + rx) >> 1ll;

        if (idx < mx)
            update(idx, val, (x << 1ll) + 1ll, lx, mx);
        else
            update(idx, val, (x << 1ll) + 2ll, mx, rx);

        tree[x] = merge(tree[(x << 1ll) + 1ll], tree[(x << 1ll) + 2ll]);
    }

    Node query(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r or l >= rx)
            return neutralValue;

        if (rx - lx == 1)
            return tree[x];

        int mx = (lx + rx) >> 1ll;
        Node ans1 = query(l, r, (x << 1ll) + 1ll, lx, mx);
        Node ans2 = query(l, r, (x << 1ll) + 2ll, mx, rx);
        Node ans = merge(ans1, ans2);
        return ans;
    }

public:
    SegmentTree(v(int) & A)
    {
        size = 1;
        while (size < (int)A.size())
            size <<= 1;
        tree.assign(size << 1ll, neutralValue);
        build(A, 0, 0, size);
    }

    void update(int idx, int val)
    {
        update(idx, val, 0, 0, size);
    }

    Node query(int l, int r)
    {
        return query(l, r, 0, 0, size);
    }
};

//------------------------------------------------------------------------------
void solve()
{
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
