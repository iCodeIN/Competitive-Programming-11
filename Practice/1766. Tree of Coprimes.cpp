
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
#include <stack>
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

//------------------------------------------------------------------------------
#define v(Type) vector<Type>
class Solution
{
public:
    int gcd(int a, int b)
    {
        return (a % b == 0) ? b : gcd(b, a % b);
    }

    int counter = 0;

    void solve(int v, v(v(int)) & adjList, v(bool) & visited, v(int) & Ans, vector<stack<pair<int, int>>> &helper, v(int) & nums)
    {
        visited[v] = true;
        int temp = -1;
        for (int i = 1; i <= 50; i++)
            if (helper[i].size() != 0 and gcd(i, nums[v]) == 1)
                if (helper[i].top().second > temp)
                    Ans[v] = helper[i].top().first, temp = helper[i].top().second;

        temp = (helper[nums[v]].size() == 0) ? -1 : helper[nums[v]].top().second;
        helper[nums[v]].push({v, ++counter});

        int child = adjList[v].size();
        for (int i = 0; i < child; i++)
            if (not visited[adjList[v][i]])
                solve(adjList[v][i], adjList, visited, Ans, helper, nums);

        helper[nums[v]].pop();
        return;
    }

    void addEdge(vector<vector<int>> &adjList, int a, int b)
    {
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges)
    {
        int n = nums.size();
        v(v(int)) adjList(n);
        for (int i = 0; i < n - 1; i++)
            addEdge(adjList, edges[i][0], edges[i][1]);
        v(bool) visited(n, false);
        v(int) Ans(n, -1);
        vector<stack<pair<int, int>>> helper(51);
        solve(0, adjList, visited, Ans, helper, nums);
        return Ans;
    }
};
