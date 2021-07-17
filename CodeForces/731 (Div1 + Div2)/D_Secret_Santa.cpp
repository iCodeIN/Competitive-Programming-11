

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
    set<int, greater<int>> outR;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        outR.insert(i);

    v(int) A(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        if (outR.find(A[i]) != outR.end())
            outR.erase(A[i]);
    }

    map<int, int> mp;
    v(int) B(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mp.count(A[i]) == 0)
        {
            mp[A[i]] = i;
            B[i] = A[i];
            ans++;
        }
        else
        {
            auto v = *outR.begin();
            if (v != i)
            {
                mp[v] = i;
                B[i] = v;
                outR.erase(v);
            }
            else
            {
                int v_ = A[i];
                B[i] = A[i];

                B[mp[A[i]]] = v;
                mp[i] = A[i];
                mp[A[i]] = i;
                outR.erase(v);
            }
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        cout << B[i] << " ";
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