

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
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
    int n, x;
    cin >> n >> x;

    if (n & 1 and (x == 0))
    {
        cout << -1 << endl;
        return;
    }

    int A[40] = {0};

    int i = 0;
    int t = n;
    while (t != 0)
    {
        if (t & 1)
            A[i] = 1;

        t >>= 1;
        i++;
    }
    for (int i = 0; i < 40; i++)
        cout << A[i] << " ";
    cout << endl;

    for (int i = 2; i < 40; i += 2)
        if (A[i] == 1)
            A[i] = 0, A[i - 1] += 2;

    bool xInc = (n & 1);
    if (xInc)
        x--, A[0]--;

    for (int i = 0; i < 40; i++)
        cout << A[i] << " ";
    cout << endl;

    for (int i = 1; i <= 32; i += 2)
    {
        while (A[i] > 0)
        {
            // cout << "x :" << x << endl;
            int temp = (1ll << i);

            if (x >= temp)
                x -= temp, A[i]--, xInc = true;
            else
                break;
        }
    }
    // for (int i = 0; i < 40; i++)
    //     cout << A[i] << " ";
    // cout << endl;
    int ans = xInc;
    for (int i = 0; i < 40; i++)
        ans += A[i];
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