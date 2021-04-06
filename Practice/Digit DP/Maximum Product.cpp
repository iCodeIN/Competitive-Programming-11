
//------------------------------------------------------------------------------
// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>
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
pair<int, string> dp[19][2][2][2];
pair<int, string> solve(string &l, string &r, int pos, bool tl, bool tr, bool start)
{

    if (pos == l.length())
        return {1, ""};

    if (dp[pos][tl][tr][start].first != -1)
        return dp[pos][tl][tr][start];
    int lb = (tl) ? l[pos] - '0' : 0;
    int ub = (tr) ? r[pos] - '0' : 9;

    pair<int, string> ans = {0, ""};

    for (int i = lb; i <= ub; i++)
    {
        int val = 1;
        if (start == false and i == 0)
            val = 1;
        else
            val = i;

        auto x = solve(l, r, pos + 1, (tl) & (i == lb), (tr) & (i == ub), start | (i > 0));
        if (x.first * val >= ans.first)
        {
            reverse(x.second.begin(), x.second.end());
            char ch = i + '0';
            x.second.push_back(ch);
            reverse(x.second.begin(), x.second.end());
            x.first *= val;
            ans = x;
        }
    }
    return dp[pos][tl][tr][start] = ans;
}
void solve()
{
    string l, r;
    cin >> l >> r;

    reverse(l.begin(), l.end());
    while (l.size() < r.size())
        l.push_back('0');

    reverse(l.begin(), l.end());

    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                for (int p = 0; p < 2; p++)
                    dp[i][j][k][p].first = -1;

    auto ans = solve(l, r, 0, 1, 1, 0);

    cout << stoll(ans.second) << endl;
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
