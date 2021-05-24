

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

void solve()
{
    int n;

    cin >> n;

    v(int) A(n);
    for (int &x : A)
        cin >> x;

    int neg = 0;
    int zero = 0;
    int pos = 0;

    map<int, int> mp;
    int min_pos = INT32_MAX;
    for (int &x : A)
    {
        neg += (x < 0);
        zero += (x == 0);
        pos += (x > 0);

        if (x < 0)
            mp[x]++;

        if (x > 0)
            min_pos = min(min_pos, x);
    }

    int ans = 0;
    if (neg == 0)
        ans = max((pos > 0) + (zero > 0) + 0ll, zero);
    else
    {
        ans = neg;
        int minDif = INT32_MAX;
        int i = 0;
        int prev = 0;
        for (auto &y : mp)
        {
            if (i != 0)
                minDif = min(minDif, abs(y.first - prev));

            prev = y.first;
            i++;
        }
        int temp1 = (zero > 0) + ((min_pos <= minDif or i == 1) and pos > 0);
        int temp2 = zero;

        ans += max(temp1, temp2);
    }

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