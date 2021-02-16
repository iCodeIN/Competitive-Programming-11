
//------------------------------------------------------------------------------
#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
// #include <cmath>
// #include <algorithm>
// #include <unordered_map>
// #include <map>
// #include <set>
#include <unordered_set>
//------------------------------------------------------------------------------
using namespace std;
//------------------------------------------------------------------------------
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
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
// class Math
// {
// public:
//     //Returns gcd of two numbers
//     int gcd(int a, int b)
//     {
//         return (a % b == 0) ? b : gcd(b, a % b);
//     }

//     //Returns lcm of two numbers
//     int lcm(int a, int b)
//     {
//         return a * (b / gcd(a, b));
//     }

//     // Returns flag array isPrime
//     // isPrime[i] = true (if i is Prime)
//     // isPrime[i] = false (if i is not Prime)
//     vector<bool> *seiveOfEratosthenes(const int N)
//     {
//         vector<bool> *isPrime = new vector<bool>(N + 1, true);
//         (*isPrime)[0] = (*isPrime)[1] = false;
//         for (int i = 2; i * i <= N; ++i)
//             if ((*isPrime)[i])
//                 for (int j = i * i; j <= N; j += i)
//                     (*isPrime)[j] = false;

//         return isPrime;
//     }

//     //Returns (x ^ n)
//     int pow(const int &x, int n)
//     {
//         if (n == 0)
//             return 1;
//         int h = pow(x, n / 2);
//         return (n & 1) ? h * h * x : h * h;
//     }

//     //Returns (x ^ n) % M
//     int pow(const int &x, int n, const int &M)
//     {
//         if (n == 0)
//             return 1;
//         int h = pow(x, n / 2) % M;
//         return (n & 1) ? (h * h * x) % M : (h * h) % M;
//     }

//     //Returns all Primes <= N
//     vector<int> *primesUptoN(const int N)
//     {
//         vector<bool> *isPrime = seiveOfEratosthenes(N);
//         vector<int> *Primes = new vector<int>;
//         if (2 <= N)
//             (*Primes).push_back(2);
//         for (int i = 3; i <= N; i += 2)
//             if ((*isPrime)[i])
//                 (*Primes).push_back(i);
//         return Primes;
//     }

// } Math;
//------------------------------------------------------------------------------
void solve()
{
    int n;
    cin >> n;
    v(string) V(n);
    unordered_set<string> S;
    for (string &x : V)
    {
        cin >> x;
        S.insert(x.substr(1));
    }

    vector<vector<bool>> A(S.size(), vector<bool>(26, false));
    vector<int> temp(S.size(), 0);

    int id = 0;
    for (auto &x : S)
    {
        for (int i = 0; i < n; ++i)
            if (V[i].substr(1) == x)
                A[id][V[i][0] - 'a'] = true, ++temp[id];
        ++id;
    }

    int ans = 0;
    n = S.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int common = 0;
            for (int k = 0; k < 26; ++k)
                if (A[i][k] == A[j][k] and A[i][k] == true)
                    common++;
            for (int k = 0; k < 26; ++k)
                if (A[j][k] == true and A[i][k] == false)
                    ans += temp[i] - common;
                else if (A[i][k] == true and A[j][k] == false)
                    ans += temp[j] - common;
        }
    }

    cout << ans << endl;
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
