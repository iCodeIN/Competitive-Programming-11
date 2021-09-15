

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
    int X;
    cin >> X;

#define f(a) a ^ X

    v(int) A(n);

    for (int &x : A)
        cin >> x;

    map<int, int> mp;

    for (int x : A)
        mp[x]++;

    int changes = INT32_MAX;
    int maxEqual = 0;

    for (auto itr : mp)
    {
        if (X > 0 and mp.count(f(itr.first)))
            maxEqual = max(maxEqual, itr.second + mp[f(itr.first)]);
        else
            maxEqual = max(maxEqual, itr.second);
    }

    for (auto itr : mp)
    {

        if (X > 0 and mp.count(f(itr.first)))
        {
            int Equal = itr.second + mp[f(itr.first)];
            if (Equal == maxEqual)
                changes = min(changes, min(itr.second, mp[f(itr.first)]));
        }
        else
        {
            int Equal = itr.second;
            if (Equal == maxEqual)
                changes = 0;
        }
    }

    cout << maxEqual << " " << changes << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //


