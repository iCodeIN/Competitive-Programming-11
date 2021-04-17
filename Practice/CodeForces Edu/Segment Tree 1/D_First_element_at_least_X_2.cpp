
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
struct item
{
    //
    int mx = INT32_MIN, idx = INT32_MAX;

    bool operator==(const item &a)
    {
        return a.mx == mx and a.idx == idx;
    }
};

class SegmentTree
{
private:
    v(item) tree;
    int size;
    item neutralValue;

    item merge(item &a, item &b)
    {
        //
        if (a.mx >= b.mx)
            return a;
        return b;
    }

    item single(int val, int idx)
    {
        //
        return {val, idx};
    }

    void init(v(int) & A)
    {
        size = 1;
        while (size < (int)A.size())
            size <<= 1;
        tree.resize(size << 1);
        build(A, 0, 0, size);
    }

    void build(v(int) & A, int x, int lx, int rx)
    {

        if (rx - lx == 1)
        {
            if (lx < (int)A.size())
                tree[x] = single(A[lx], lx);

            return;
        }

        int mx = (lx + rx) >> 1;

        build(A, (x << 1) + 1, lx, mx);
        build(A, (x << 1) + 2, mx, rx);

        tree[x] = merge(tree[(x << 1) + 1], tree[(x << 1) + 2]);
    }

    void update(int &idx, int &val, int x, int lx, int rx)
    {

        if (rx - lx == 1)
        {
            tree[x] = single(val, tree[x].idx);
            return;
        }

        int mx = (lx + rx) >> 1ll;

        if (idx < mx)
            update(idx, val, (x << 1) + 1, lx, mx);
        else
            update(idx, val, (x << 1) + 2, mx, rx);

        tree[x] = merge(tree[(x << 1) + 1], tree[(x << 1) + 2]);
    }

    item query(int x, int lx, int rx, int &k,int &l)
    {

        if(l >= rx)
            return neutralValue;
        
        if (rx - lx == 1)
        {
            if (tree[x].mx >= k)
                return tree[x];
            else
                return neutralValue;
        }

        if (tree[x].mx < k)
            return neutralValue;

        int mx = (lx + rx) >> 1;

        item ans1 = query((x << 1) + 1, lx, mx, k,l);
        item ans2 = (ans1 == neutralValue) ? query((x << 1) + 2, mx, rx, k,l) : neutralValue;

        return merge(ans1, ans2);
    }

public:
    SegmentTree(v(int) & A)
    {
        init(A);
        return;
    }

    void update(int &idx, int &val)
    {
        update(idx, val, 0, 0, size);
        return;
    }

    item query(int &k,int &l)
    {
        return query(0, 0, size, k,l);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    v(int) A(n);
    for (int &x : A)
        cin >> x;
    SegmentTree st(A);
    while (q--)
    {
        int op;
        cin >> op;

        if (op == 2)
        {
            int k,j;
            cin >> k >> j;
            auto ans = st.query(k,j);
            if (ans.idx == INT32_MAX)
                ans.idx = -1;
            cout << ans.idx << endl;
        }
        else
        {
            int i, v;
            cin >> i >> v;

            st.update(i, v);
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