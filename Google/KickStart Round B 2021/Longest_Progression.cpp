
//------------------------------------------------------------------------------
#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
// #include <cmath>
// #include <algorithm>
#include <unordered_map>
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

bool check(v(int) & A, int s, int e, unordered_map<int, int> &mp)
{

    if (e - s + 1 == 2)
        return true;
    int mx = 0;
    int d = -1;

    for (auto &x : mp)
    {
        if (x.second > mx)
        {
            mx = x.second;
            d = x.first;
        }
    }
    int rem = e - s - mx;
    if (rem > 2)
    {
        // cout << 1;
        return false;
    }

    if (rem == 0)
    {
        // cout << 2;
        return true;
    }

    if (rem == 1)
    {
        if (A[s + 1] - A[s] != d)
        {
            int temp = 2 * A[s + 1] - A[s + 2];
            // cout << 3;
            return A[s + 1] - temp == d;
        }
        if (A[e] - A[e - 1] != d)
        {
            int temp = 2 * A[e - 1] - A[e - 2];
            // cout << 4;
            return temp - A[e - 1] == d;
        }
        // cout << 5;
        return false;
    }

    for (int i = s + 1; i < e; i++)
    {
        int p = A[i] - A[i - 1];
        int f = A[i + 1] - A[i];
        bool ans = false;
        // This needs or its next to be changed
        if (p != d or f != d)
        {
            if ((A[i - 1] + A[i + 1]) & 1)
            {
                // cout << A[i - 1] + A[i + 1] << "| ";
                ans = false;
            }
            else
            {

                int temp = (A[i - 1] + A[i + 1]) >> 1;
                // cout << 7;
                ans = temp - A[i - 1] == d and A[i + 1] - temp == d;
            }

            if (ans == false and i + 2 <= e)
            {
                int temp = 2 * A[i] - A[i - 1];
                // cout << 7;
                ans = temp - A[i] == d and A[i + 2] - temp == d;
            }
            return ans;
        }
    }
    // cout << 8;
    return false;
}

bool isgood(v(int) & A, int window_size)
{
    unordered_map<int, int> mp;
    for (int i = 1; i < window_size; i++)
        mp[A[i] - A[i - 1]]++;

    if (mp.size() <= 3)
    {
        bool ans = check(A, 0, window_size - 1, mp);
        // cout << " ";
        if (ans)
            return true;
    }
    for (int i = 1, j = window_size; j < A.size(); i++, j++)
    {
        mp[A[i] - A[i - 1]]--;
        if (mp[A[i] - A[i - 1]] == 0)
            mp.erase(A[i] - A[i - 1]);
        mp[A[j] - A[j - 1]]++;

        if (mp.size() <= 3)
        {
            bool ans = check(A, i, j, mp);
            // cout << " ";
            if (ans)
                return true;
        }
    }
    // cout << " ";
    return false;
}

int solve(v(int) & A, int n)
{
    int l = 2;
    int r = n + 1;
    while (r - l > 1)
    {
        int m = (l + r) >> 1;

        // cout << m << " : ";
        if (isgood(A, m))
            l = m;
        else
            r = m;
        // cout << endl;
    }
    return l;
}

void solve()
{
    int n;
    cin >> n;

    v(int) A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int ans = solve(A, n);

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
