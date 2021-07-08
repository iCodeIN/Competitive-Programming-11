

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

    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        mp[temp]++;
    }

    for (int i = 0; i < n; i++)
    {

        auto itr1 = mp.lower_bound(n - A[i]);
        auto itr2 = mp.lower_bound(0);

        if (itr1 != mp.end())
        {
            cout << (A[i] + itr1->first) % n << " ";
            mp[itr1->first]--;
            if (mp[itr1->first] == 0)
            {
                mp.erase(itr1->first);
            }
        }
        else
        {
            cout << (A[i] + itr2->first) % n << " ";
            mp[itr2->first]--;
            if (mp[itr2->first] == 0)
            {
                mp.erase(itr2->first);
            }
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
