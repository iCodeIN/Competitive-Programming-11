

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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    v(v(int)) pre(26, v(int)(n, 0));
    int i = 0;
    for (char x : s)
    {
        pre[x - 'a'][i]++;
        i++;
    }
    for (int i = 0; i < 26; i++)
    {
        for (int j = 1; j < n; j++)
        {
            pre[i][j] += pre[i][j - 1];
        }
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            int f = pre[i][r];
            if (l > 0)
                f -= pre[i][l - 1];
            ans += (i + 1) * f;
        }
        cout << ans << endl;
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