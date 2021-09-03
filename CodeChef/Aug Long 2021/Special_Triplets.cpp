

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

const int N = 1e5;

vector<int> divisors[N + 1];

int f(int B, int n)
{
    int ans = 0;
    for (int d : divisors[B])
        ans += ((n - d) / B) + 1;

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    int ans = 0;
    for (int B = 1; B <= n; B++)
        ans += f(B, n);

    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    for (int i = 1; i <= N; i++)
        for (int j = 2 * i; j <= N; j += i)
            divisors[j].push_back(i);

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //