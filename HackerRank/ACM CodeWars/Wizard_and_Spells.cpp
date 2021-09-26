

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
    int n, q;
    cin >> n;

    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;

        mp[l] += x;
        mp[r + 1] -= x;
    }
    int prev = 0;
    for (auto &v : mp)
    {
        v.second += prev;
        prev = v.second;
    }

    cin >> q;

    while (q--)
    {
        int pos;

        cin >> pos;

        auto itr = mp.upper_bound(pos);

        if (itr != mp.begin())
        {
            itr--;
            cout << itr->second << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //


