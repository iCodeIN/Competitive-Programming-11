
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
// #define int long long int
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

#define maxn 800001
#define max_elem 200001
int segmentTree[maxn];

void update(int node, int a, int b, int x, int diff)
{

    if (a == b && a == x)
    {

        segmentTree[node] += diff;
        return;
    }

    if (x >= a && x <= b)
    {
        update(node * 2, a, (a + b) / 2, x, diff);
        update(node * 2 + 1, (a + b) / 2 + 1, b, x, diff);

        segmentTree[node] = segmentTree[node * 2] +
                            segmentTree[node * 2 + 1];
    }
}

int findKth(int node, int a, int b, int k)
{

    if (a != b)
    {

        if (segmentTree[node * 2] >= k)
            return findKth(node * 2, a, (a + b) / 2, k);

        return findKth(node * 2 + 1, (a + b) / 2 + 1,
                       b, k - segmentTree[node * 2]);
    }

    return (segmentTree[node]) ? a : -1;
}

void insert(int x)
{
    update(1, 0, max_elem, x, 1);
}

void delet(int x)
{
    update(1, 0, max_elem, x, -1);
}

int k;
int median()
{
    int k_ = (segmentTree[1] + 1) / 2;
    return findKth(1, 0, max_elem, k_);
}
//------------------------------------------------------------------------------
void solve()
{
    int n, k;
    cin >> n >> k;
    v(int) A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < k; i++)
        insert(A[i]);
    int ans = median();
    for (int i = 1; k + i - 1 < n; i++)
    {
        delet(A[i - 1]);
        insert(A[k + i - 1]);
        ans = max(ans, median());
    }
    cout << ans << endl;
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
