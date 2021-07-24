

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
    int n, m, l;
    cin >> n >> m >> l;

    int mp[n + 1] = {0};
    for (int i = 0; i < m; i++)
    {
        int N;
        cin >> N;

        for (int j = 0; j < N; j++)
        {
            int id;
            cin >> id;

            mp[id] = i + 1;
        }
    }

    int A[l];

    for (int i = 0; i < l; i++)
        cin >> A[i];

    int ans = 0;

    for (int i = 0; i < l; i++)
    {
        ++ans;

        int j = i;

        while (j < l and mp[A[j]] == mp[A[i]])
            j++;

        i = j - 1;
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