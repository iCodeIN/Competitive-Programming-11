
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

int f(string &cur, string &prev)
{
    for (int i = 0; i < cur.length(); i++)
    {
        if (cur[i] < prev[i])
        {
            int ans = 0;
            while (cur.length() <= prev.length())
                cur += '0', ans++;
            return ans;
        }
        else if (cur[i] > prev[i])
        {
            int ans = 0;
            while (cur.length() < prev.length())
                cur += '0', ans++;
            return ans;
        }
    }

    for (int j = prev.length() - 1; j >= cur.length(); j--)
        if (prev[j] != '9')
        {
            int i = cur.length();
            int ans = 0;
            while (i < j)
            {
                cur += prev[i];
                i++;
                ans++;
            }
            cur.push_back(prev[i] + 1);
            i++;
            ans++;
            while (i < prev.length())
            {
                cur += '0';
                i++;
                ans++;
            }
            return ans;
        }
    int ans = 0;
    while (cur.length() <= prev.length())
        cur += '0', ans++;
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    v(string) A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int ans = 0;

    for (int i = 1; i < n; i++)
    {

        if (A[i].length() > A[i - 1].length())
            continue;
        else if (A[i].length() == A[i - 1].length() and stoll(A[i - 1]) < stoll(A[i]))
            continue;

        else
            ans += f(A[i], A[i - 1]);
    }
    cout << ans << endl;
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
