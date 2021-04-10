
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
void solve()
{
    int a, b;
    string s;
    cin >> a >> b >> s;

    for (int i = 0; i < s.length(); i++)
        if (s[i] == '0')
            a--;
        else if (s[i] == '1')
            b--;

    bool check = a >= 0 and b >= 0;

    for (int i = 0, j = s.length() - 1; i < j; i++, j--)
        if (s[i] != '?' and s[j] != '?' and s[i] != s[j])
            check = false;

    bool ans = check;
    if (ans)
    {
        for (int i = 0, j = s.length() - 1; i < j; i++, j--)
            if (s[i] == '?' and s[j] != '?')
            {
                s[i] = s[j];
                a -= (s[j] == '0');
                b -= (s[j] == '1');
            }
            else if (s[i] != '?' and s[j] == '?')
            {
                s[j] = s[i];
                a -= (s[i] == '0');
                b -= (s[i] == '1');
            }
        ans = a >= 0 and b >= 0;
        for (int i = 0, j = s.length() - 1; i <= j and ans; i++, j--)
        {
            if (s[i] == '?')
            {
                if (i < j)
                {
                    if (a >= 2)
                    {
                        s[i] = s[j] = '0';
                        a -= 2;
                    }
                    else if (b >= 2)
                    {
                        s[i] = s[j] = '1';
                        b -= 2;
                    }
                    else
                    {
                        ans = false;
                        break;
                    }
                }
                else
                {
                    if (a == 1)
                    {
                        s[i] = '0';
                        a--;
                    }
                    else if (b == 1)
                    {
                        s[i] = '1';
                        b--;
                    }
                    else
                    {
                        ans = false;
                        break;
                    }
                }
            }
        }
    }
    if (ans == false)
        cout << "-1";
    else
        cout << s;
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
