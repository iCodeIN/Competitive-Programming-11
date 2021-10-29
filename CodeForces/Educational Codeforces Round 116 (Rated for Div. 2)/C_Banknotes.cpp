

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

int pow(int x, int n)
{
    if (n == 0)
        return 1;
    if (n & 1)
        return x * pow(x, n - 1);
    int h = pow(x, n >> 1);
    return h * h;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    k++;
    v(int) A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        A[i] = pow(10, A[i]);
    }

    string ans = "";
    for (int i = 0; i < n - 1 and k > 0; i++)
    {
        int cur = (A[i + 1] / A[i]) - 1;
        int m = min(cur, k);
        ans = to_string(min(cur, k)) + ans;
        k -= min(cur, k);
    }
    if (k > 0)
        ans = to_string(k) + ans;
    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //