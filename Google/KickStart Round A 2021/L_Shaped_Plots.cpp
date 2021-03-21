
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

int solve(int a, int b)
{
    if (a < 2 or b < 2)
        return 0;

    int ans = min(a / 2, b) - 1 + min(a, b / 2) - 1;

    return ans;
}

void solve()
{
    int m, n;
    cin >> m >> n;
    v(v(int)) A(m, v(int)(n));
    v(v(int)) up(m, v(int)(n, 0));
    v(v(int)) down(m, v(int)(n, 0));
    v(v(int)) right(m, v(int)(n, 0));
    v(v(int)) left(m, v(int)(n, 0));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    for (int i = 0; i < m; i++)
        for (int j = n - 1; j >= 0; j--)
        {
            if (j == n - 1)
                right[i][j] = (A[i][j] == 1);

            else if (A[i][j] == 1)
                right[i][j] = right[i][j + 1] + 1;
        }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
                left[i][j] = (A[i][j] == 1);

            else if (A[i][j] == 1)
                left[i][j] = left[i][j - 1] + 1;
        }

    for (int i = 0; i < m; i++)
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == 0)
                up[i][j] = (A[i][j] == 1);
            else if (A[i][j] == 1)
                up[i][j] = up[i - 1][j] + 1;
        }

    for (int i = m - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1)
                down[i][j] = (A[i][j] == 1);

            else if (A[i][j] == 1)
                down[i][j] = down[i + 1][j] + 1;
        }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //up,right
            ans += solve(up[i][j], right[i][j]);
            // up,left
            ans += solve(up[i][j], left[i][j]);
            // down,right
            ans += solve(down[i][j], right[i][j]);
            // down,left
            ans += solve(down[i][j], left[i][j]);

            // cout << i << " " << j << " " << ans << endl;
        }
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
