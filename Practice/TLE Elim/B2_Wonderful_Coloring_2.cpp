

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
    map<int, vector<int>> mp;
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        mp[val].push_back(i);
    }
    v(int) Ans(n);
    int prev = 0;
    map<int, int> color;
    for (auto itr : mp)
    {
        int ub = min((int)itr.second.size(), k);
        for (int i = 0; i < ub; i++, prev++)
        {
            prev %= k;
            Ans[itr.second[i]] = prev + 1;
            color[prev + 1]++;
        }
    }
    int minF = INT32_MAX;
    for (auto itr : color)
    {
        minF = min(minF, itr.second);
    }

    for (int &x : Ans)
    {
        if (color[x] > minF)
        {
            color[x]--;
            x = 0;
        }
    }
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