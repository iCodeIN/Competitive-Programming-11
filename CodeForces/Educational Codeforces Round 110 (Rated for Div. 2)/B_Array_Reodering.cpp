

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
#include <map>
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
v(v(int)) factors(100001);
void pre()
{
    int n = 100000;

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            factors[j].push_back(i);
}

void solve()
{
    int n;
    cin >> n;
    v(int) A(n);
    for (int &x : A)
        cin >> x;
    map<int, int> mp;
    int ans = 0;
    int i = 1;
    for (int x : A)
        if (x & 1)
        {
            if (x > 1)
                mp[x]++;
        }
        else
        {
            ans += (n - i);
            i++;
        }

    // cout << ans << endl;
    for (int x : A)
    {
        if (mp[x] > 0)
        {
            for (int y : factors[x])
                if (x != y)
                    ans += mp[x] * mp[y];
                else
                    ans += (mp[x] * (mp[x] - 1)) / 2;

            mp[x] = 0;
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    FastIO;
    pre();
    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //