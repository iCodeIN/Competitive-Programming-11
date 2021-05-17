

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>
#include <vector>

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

using namespace std;

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#define w(T)  \
    int T;    \
    cin >> T; \
    while (T--)

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define v(Type) vector<Type>
#define endl "\n"
#define int long long int
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
const int N = 1000000;
static int phi[4000002];
static int spf[4000002];
static int a[1000001];

void pre(int n)
{
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i, spf[i] = i;

    for (int i = 2; i <= n; i++)
        if (phi[i] == i)
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;

    for (int i = 2; i <= n; i++)
        if (spf[i] == i)
            for (int j = i * i; j <= n; j += i)
                if (spf[j] == j)
                    spf[j] = i;
}

int calculate(vector<pair<int, int>> &A, int &t, int pos = 0, int num = 1)
{
    if (num > t)
        return 0;
    if (pos == A.size())
        return (t / num) * phi[num];

    int ans = 0;
    int cur = 1;
    for (int i = 0; i <= A[pos].second; i++, cur *= A[pos].first)
        ans += calculate(A, t, pos + 1, num * cur);

    return ans;
}

int f(int k)
{
    if (a[k] != -1)
        return a[k];

    int n = 4 * k + 1;

    if (spf[n] == n)
        return a[k] = 6 * k;

    vector<pair<int, int>> A;

    while (n != 1)
    {
        if (A.size() == 0 or spf[n] != A[A.size() - 1].first)
            A.push_back({spf[n], 1});
        else
            A[A.size() - 1].second++;

        n /= spf[n];
    }

    n = 4 * k + 1;
    int t = 2 * k - 1;

    int ans = calculate(A, t) + n;

    return a[k] = ans;
}

void solve()
{
    int k;
    cin >> k;

    int ans = f(k);
    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    pre(4 * N + 1);

    for (int i = 1; i <= N; i++)
        a[i] = -1;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
