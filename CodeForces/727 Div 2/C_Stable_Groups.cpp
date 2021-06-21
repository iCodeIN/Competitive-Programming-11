

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
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
    int n, k, x;
    cin >> n >> k >> x;
    int sum = 0;
    int groups = 1;
    v(int) A(n);
    for (int &x : A)
        cin >> x;
    sort(all(A));
    map<int, int> mp;
    // cout << A[0] << " ";
    for (int i = 1; i < n; i++)
    {

        if (A[i] - A[i - 1] > x)
        {
            // cout << " | " << A[i] << " ";
            int r = (A[i] - A[i - 1]) / x;
            if ((A[i] - A[i - 1]) % x == 0)
                r--;
            mp[r]++;
            groups++;
        }
        else
        {
            // cout << A[i] << " ";
        }
    }
    // cout << endl;
    for (auto temp : mp)
    {
        // cout << temp.first << " -> " << temp.second << endl;
        int f = temp.second;
        while (f-- and k >= temp.first)
        {

            groups--;
            k -= temp.first;
        }
        if (k < temp.first)
            break;
    }

    int ans = max(1ll, groups);

    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //