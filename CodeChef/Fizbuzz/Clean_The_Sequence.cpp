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

#define pair <int, int> pii
#define ff first
#define ss second

#define int long long
#define mod 1000000007ll
#define endl "\n"
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
void solve()
{
    int n, k;
    cin >> n >> k;

    v(int) A(n);

    for (int &x : A)
        cin >> x;

    v(int) B;
    map<int, v(int)> mp;
    int prev = -1;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == prev)
            continue;
        mp[A[i]].push_back(B.size());
        B.push_back(A[i]);
        prev = A[i];
    }

    n = B.size();
    A = B;

    for (int i = 1; i <= k; i++)
    {
        int ans = n;

        for (auto itr : mp[i])
        {
            int idx = itr;

            if (idx - 1 >= 0 and idx + 1 <= n)
            {
                if (A[idx - 1] == A[idx + 1])
                {
                    ans--;
                }
            }
            ans--;
        }
        cout << max(0ll, ans - 1) << " ";
    }
    cout << endl;
}
int32_t main()
{
    FastIO;

    w(T)
    {
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //