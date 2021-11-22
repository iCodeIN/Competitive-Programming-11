

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
#include <bits/stdc++.h>
// #include <cmath>
// #include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>
// #include <vector>

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

#define nC2(v) (v * (v - 1)) / 2

void solve()
{
    int n;
    cin >> n;

    v(int) A(n);

    for (int &x : A)
        cin >> x;

    sort(all(A));
    map<int, int> mp;
    int ans = 0;
    int f1[] = {-2, -2, -2, -1, -1, 0};
    int f2[] = {-2, -1, 0, -1, 0, 0};
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        for (int j = 0; j < 6; j++)
        {
            int x = A[i] + f1[j];
            int y = A[i] + f2[j];

            if (x == y)
            {
                cur += nC2(mp[x]);
            }
            else
            {
                cur += mp[x] * mp[y];
            }
        }
        mp[A[i]]++;
        ans += cur;
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