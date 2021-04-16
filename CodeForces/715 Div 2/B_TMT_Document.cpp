
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
bool check(string &s)
{
    int tc = 0;
    int mc = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == 'T')
            tc++;
        else
            mc++;
    return tc == 2 * mc;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ans = check(s);
    if (ans)

    {
        v(int) tl(n, 0), tr(n, 0), ml(n, 0), mr(n, 0);
        tl[0] = (s[0] == 'T');
        ml[0] = (s[0] == 'M');

        for (int i = 1; i < n; i++)
        {
            if (s[i] == 'T')
                tl[i]++;
            else
                ml[i]++;
            tl[i] += tl[i - 1];
            ml[i] += ml[i - 1];
        }

        tr[n - 1] = (s[n - 1] == 'T');
        mr[n - 1] = (s[n - 1] == 'M');

        for (int i = n - 2; i >= 0; i--)
        {
            if (s[i] == 'T')
                tr[i]++;
            else
                mr[i]++;
            tr[i] += tr[i + 1];
            mr[i] += mr[i + 1];
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'M')
            {
                int l = tl[i] - (ml[i] - 1);
                int r = tr[i] - (mr[i] - 1);

                if (l >= 1 and r >= 1)
                    continue;
                else
                {
                    // cout << l << " " << r << endl;
                    ans = false;

                    break;
                }
            }
        }
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
