
//------------------------------------------------------------------------------
#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
// #include <cmath>
#include <algorithm>
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
struct Node
{
    int id;
    int rank;
};
bool comp(Node a, Node b)
{
    return a.rank < b.rank;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    v(int) C_Rank(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> C_Rank[i];
    }
    v(Node) S(m + 1);
    S[0].rank = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> S[i].rank;
        S[i].id = i;
    }
    sort(S.begin() + 1, S.end(), comp);

    v(v(int)) Choices(m + 1);
    for (int i = 1; i <= m; i++)
    {
        int size;
        cin >> size;
        Choices[i].resize(size);
        for (int j = 0; j < size; j++)
            cin >> Choices[i][j];
    }
    v(bool) filled(n + 1, false);
    int ans = INT32_MAX;
    for (int i = 1; i <= m and ans == INT32_MAX; i++)
    {
        int bestChoice = INT32_MAX;
        int bestRank = INT32_MAX;
        for (int j = 0; j < Choices[S[i].id].size(); j++)
            if (C_Rank[Choices[S[i].id][j]] < bestRank and filled[Choices[S[i].id][j]] == false)
            {
                bestChoice = Choices[S[i].id][j];
                bestRank = C_Rank[Choices[S[i].id][j]];
            }
        if (bestChoice != INT32_MAX)
        {
            filled[bestChoice] = true;
            // cout << S[i].id << " " << bestChoice << endl;
        }

        if (S[i].id == 1)
        {
            if (bestChoice == INT32_MAX)
                ans = 0;
            else
                ans = bestChoice;
            break;
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
