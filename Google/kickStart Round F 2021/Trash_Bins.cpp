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
    int n;
    cin >> n;
    string s;
    cin >> s;

    v(int) pre(n, INT32_MAX), suf(n, INT32_MAX);

    pre[0] = (s[0] == '1') ? 0 : pre[0];
    suf[n - 1] = (s[n - 1] == '1') ? n - 1 : suf[n - 1];

    for (int i = 1; i < n; i++)
        if (s[i] == '1')
            pre[i] = i;
        else
            pre[i] = pre[i - 1];

    for (int i = n - 2; i >= 0; i--)
        if (s[i] == '1')
            suf[i] = i;
        else
            suf[i] = suf[i + 1];
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int p = pre[i];
        int s = suf[i];
        
        ans += min(abs(p - i), abs(s - i));
    }

    cout << ans << endl;
}

int32_t main()
{
    FastIO;
    int test = 1;
    w(T)
    {
        cout << "Case #" << test++ << ": ";
        solve();
    }
    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //