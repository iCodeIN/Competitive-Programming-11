
//------------------------------------------------------------------------------
#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
#include <cmath>
// #include <algorithm>
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

int getMax(int start, int end, v(v(int)) & SPARSE)
{

    int window_size = end - start + 1;
    int w = log2(window_size);
    return max(SPARSE[start][w], SPARSE[start + window_size - (1 << w)][w]);
}

void solve()
{
    int n;
    cin >> n;
    v(int) A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    v(int) L(n, 0), R(n, 0);

    int col = log2(n) + 1;
    vector<vector<int>> SPARSE(n, vector<int>(col, -1));

    for (int i = 0; i < n; i++)
        SPARSE[i][0] = A[i];

    for (int j = 1; j < col; j++)
    {
        int prev_window_size = (1 << (j - 1));
        for (int i = 0; i + prev_window_size < n; i++)
            SPARSE[i][j] = max(SPARSE[i][j - 1], SPARSE[i + prev_window_size][j - 1]);
    }
    map<int, int> mp;
    for (int i = n - 1; i >= 0; i--)
    {
        if (mp.count(A[i]) > 0)
        {
            if (getMax(i, mp[A[i]], SPARSE) <= A[i])
                R[i] = R[mp[A[i]]] + 1;
        }
        mp[A[i]] = i;
    }
    mp.clear();
    for (int i = 0; i < n; i++)
    {
        if (mp.count(A[i]) > 0)
        {
            if (getMax(mp[A[i]], i, SPARSE) <= A[i])
                L[i] = L[mp[A[i]]] + 1;
        }
        mp[A[i]] = i;
    }

    for (int i = 0; i < n; i++)
        cout << L[i] + R[i] << " ";
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
