

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
    cin.tie(NULL);

#define v(Type) vector<Type>
#define all(x) x.begin(), x.end()

#define int long long int
#define mod 1000000007ll
// #define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

void solve()
{

    int n;
    cin >> n;

    map<int, int> mp;
    v(int) Ans;

    // i -> rightmost having 0 inv
    int l = 1;
    int r = n + 1;

    while (r - l > 1)
    {
        int m = (l + r) >> 1ll;

        if (mp.count(m) == 0)
        {
            cout << "? " << 1 << " " << m << endl;
            fflush(stdout);
            cin >> mp[m];
        }

        if (mp[m] == 0)
            l = m;
        else
            r = m;
    }
    Ans.push_back(l);

    // k -> leftmost having total inv

    if (mp.count(n) == 0)
    {
        cout << "? " << 1 << " " << n << endl;
        fflush(stdout);
        cin >> mp[n];
    }

    l = Ans[0] + 2;
    r = n;

    while (r - l > 1)
    {
        int m = (l + r) >> 1ll;

        if (mp.count(m) == 0)
        {
            cout << "? " << 1 << " " << m << endl;
            fflush(stdout);
            cin >> mp[m];
        }

        if (mp[m] == mp[n])
            r = m;
        else
            l = m;
    }

    Ans.push_back(-1);
    Ans.push_back(r);

    // j

    l = Ans[0] + 1;
    r = Ans[2];

    // rightmost having = f*(f + 1) / 2
    while (r - l > 1)
    {
        int m = (l + r) >> 1ll;

        int f = m - Ans[0];

        if (mp.count(m) == 0)
        {
            cout << "? " << 1 << " " << m << endl;

            cin >> mp[m];
        }

        if (f & 1ll)
            f = (((f + 1) / 2ll) * f);
        else
            f = (f / 2ll) * (f + 1);

        if (mp[m] == f)
            l = m;
        else
            r = m;
    }

    Ans[1] = l + 1;

    cout << "! ";

    for (int x : Ans)
        cout << x << " ";

    cout << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //