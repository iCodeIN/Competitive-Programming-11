

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
#include <map>
#include <set>
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
    v(int) A(n), B(n);

    for (int &x : A)
        cin >> x;
    for (int &x : B)
        cin >> x;

    set<int> ans;
    for (int i = 0; i < n; i++)
    {
        int x = A[0] ^ B[i];
        map<int, int> mp;
        for (int j = 0; j < n; j++)
            mp[B[j]]++;
        bool ok = true;
        for (int j = 0; j < n; j++)
        {
            if (mp[x ^ A[j]] > 0)
                mp[x ^ A[j]]--;
            else
            {
                ok = false;
                break;
            }
        }
        if (ok)
            ans.insert(x);
    }
    cout << ans.size() << endl;
    while (ans.size() > 0)
    {
        cout << *ans.begin() << endl;
        ans.erase(ans.begin());
    }

    cout << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //