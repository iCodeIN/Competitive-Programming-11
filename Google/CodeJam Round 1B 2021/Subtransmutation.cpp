
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

void isgood(v(int) & A, int n, v(int) & C, int a, int b)
{

    if (n <= 1)
        return;

    if (n >= A.size() or C[n] > A[n])
    {
        C[n]--;
        if (n >= a + 1)
        {
            C[n - a]++;
            isgood(A, n - a, C, a, b);
        }
        if (n >= b + 1)
        {
            C[n - b]++;
            isgood(A, n - b, C, a, b);
        }
    }
}

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    v(int) A(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> A[i];

    int ans = n + 20;

    int l = n;
    int r = n + 21;

    while (r - l > 1)
    {
        v(int) B = A;
        int m = (l + r) >> 1;
        v(int) C(m + 1, 0);
        C[m]++;
        isgood(B, m, C, a, b);

        bool good = true;
        // cout << m << " : ";
        // for (int i = 1; i <= n; i++)
        //     cout << C[i] << " ";
        // cout << endl;
        for (int i = 1; i <= n; i++)
            if (B[i] > C[i])
                good = false;

        if (good)
            r = m;
        else
            l = m;
    }
    ans = r;

    if (ans == n + 20)
        cout << "IMPOSSIBLE";
    else
        cout << ans;
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
