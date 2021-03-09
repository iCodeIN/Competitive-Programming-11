
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

int bs1(v(int) & A, int l, int r, int x)
{
    while (r - l > 1)
    {
        int m = (l + r) >> 1;

        if (A[m] >= x)
            r = m;
        else
            l = m;
    }
    return r;
}

int rev(int n)
{
    int temp = 0;

    while (n)
    {
        temp *= 10;
        temp += n % 10;
        n /= 10;
    }

    return temp;
}

void solve()
{
    int h, m;
    cin >> h >> m;

    string s;
    cin >> s;

    int hh = (s[0] - '0') * 10 + (s[1] - '0');
    int mm = (s[3] - '0') * 10 + (s[4] - '0');

    v(int) A(10, -1);

    A[0] = 0;
    A[1] = 1;
    A[2] = 5;
    A[5] = 2;
    A[8] = 8;

    v(int) Min, Hour;

    for (int i = 0; i < min(10ll, m); i++)
        if (A[i % 10] != -1 and A[i / 10] != -1 and 10 * i < h)
            Min.push_back(i);

    for (int i = 10; i < m; i++)
        if (A[i % 10] != -1 and A[i / 10] != -1 and rev(i) < h)
            Min.push_back(i);

    for (int i = 0; i < min(10ll, h); i++)
        if (A[i % 10] != -1 and A[i / 10] != -1 and 10 * i < m)
            Hour.push_back(i);

    for (int i = 10; i < h; i++)
        if (A[i % 10] != -1 and A[i / 10] != -1 and rev(i) < m)
            Hour.push_back(i);

    int hs = bs1(Hour, -1, Hour.size(), hh);
    int ms = bs1(Min, -1, Min.size(), mm);

    hs %= Hour.size();
    ms %= Min.size();

    if (Hour[hs] == hh)
    {
        if (Min[ms] < mm)
        {
            hs++;
            hs %= Hour.size();
            ms = 0;
        }
    }
    else
    {
        ms = 0;
    }

    string hans = to_string(Hour[hs]);
    string mans = to_string(Min[ms]);

    if (hans.size() == 1)
        cout << "0";

    cout << hans << ":";

    if (mans.size() == 1)
        cout << "0";

    cout << mans;
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
