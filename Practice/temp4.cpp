
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

struct node
{
    int p = -1, s = -1;
};
node dp[1000][1000][2];

node solve(string &s, int start, int end, int player)
{

    char ch = (player == 0) ? 'I' : 'O';
    if (s[start] == s[end] and s[start] != ch)
        return dp[start][end][player] = {player ^ 1, end - start + 1};

    node ans = {player ^ 1, INT32_MAX};
    node temp;

    if (dp[start][end][player].s != -1)
        return dp[start][end][player];
    if (start == end)
    {
        if (s[start] == ch)
        {
            ans.p = player;
            ans.s = 0;
        }
        else
        {
            ans.p = player ^ 1;
            ans.s = 1;
        }
    }
    else
    {

        if (s[start] == ch)
        {

            temp = solve(s, start + 1, end, player ^ 1);
            ans = temp;
        }

        if (s[end] == ch)
        {
            temp = solve(s, start, end - 1, player ^ 1);
            if (temp.p == player)
            {
                if (ans.p == (player ^ 1) or ans.s < temp.s)
                    ans = temp;
            }
            else if (ans.p == (player ^ 1) and temp.s < ans.s)
                ans = temp;
        }
    }
    return dp[start][end][player] = ans;
}

void solve()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
        for (int j = 0; j < s.length(); j++)
            for (int k = 0; k < 2; k++)
                dp[i][j][k].s = dp[i][j][k].p = -1;

    auto ans = solve(s, 0, s.length() - 1, 0);
    char winner = 'I';
    if (ans.p == 1)
        winner = 'O';
    cout << winner << " " << ans.s + 1 << endl;
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
