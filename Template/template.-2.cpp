// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
// #include <algorithm>
// #include <cmath>
// #include <cstring>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// #include <stack>

using namespace std;

#define int long long
#define v(T) vector<T>
#define f1(i, a, b, c) for (int i = a; i <= b; i += c)
#define f(i, a, b) f1(i, a, b, 1)
#define endl "\n"
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;

int pow(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}

int pow(int x, int n, int M)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans = (ans * x) % M;
        x = (x * x) % M;
        n >>= 1;
    }
    return ans;
}

int modinv(int x, int M)
{
    return pow(x, M - 2, M);
}

int gcd(int a, int b)
{
    while (a % b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return b;
}

int lcm(int a, int b)
{
    return a * (b / gcd(a, b));
}

v(bool) isP;
void seive(int n)
{
    f(i, 0, n) isP[i] = true;
    isP[0] = isP[1] = false;
    f(i, 2, n) if (isP[i]) f1(j, i * i, n, i) isP[j] = false;
}

void solve()
{
}

int32_t main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // const int N = 1e6;
    // isP.resize(N+1);
    // seive(N);

    int t = 1;
    cin >> t;
    f(i, 1, t)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}