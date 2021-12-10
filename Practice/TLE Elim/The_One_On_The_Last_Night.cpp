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

#define pair <int, int> pii
#define ff first
#define ss second

#define int long long
#define mod 1000000007ll
#define endl "\n"
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
// backtracking
int solve(string &s, int n, int k)
{
    if (n == 0)
    {
        int ans = 1;
        for (char ch : s)
            ans *= (ch - '0');
        // cout << s << endl;
        return ans;
    }

    int ans = solve(s, n - 1, k);
    if (s[n - 1] != '9' and k > 0)
    {
        s[n - 1]++;
        ans = max(ans, solve(s, n, k - 1));
        s[n - 1]--;
    }
    return ans;
}

void solve()
{
    string s;
    cin >> s;

    int k;
    cin >> k;

    int n = s.length();
    int ans = solve(s, n, k);
    cout << ans << endl;
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