

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
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define v(Type) vector<Type>
#define all(x) x.begin(), x.end()

#define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int LCM(int a, int b)
{
    if (b >= INT32_MAX)
        return b;
    return b * (a / gcd(a, b));
}

int pre[100001];

void solve()
{
    int n;
    cin >> n;
    v(int) A(n);
    for (int &x : A)
        cin >> x;

    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        ans &= (A[i] % pre[i] != 0);
    }
    if (ans)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
}

int32_t main()
{
    FastIO;
    pre[0] = 2;
    for (int i = 1; i <= 100000; i++)
    {
        pre[i] = LCM(i + 2, pre[i - 1]);
    }
    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //