// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
/* author : pasricha_dhruv */
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
// #include <set>
#include <queue>
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
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.length();
    v(int) pre(n, 0);

    pre[0] = s[0] == 'X';
    for (int i = 1; i < n; i++)
        if (s[i] == 'X')
            pre[i] = 1 + pre[i - 1];
    queue<int> q;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {

        if (s[i] == 'X')
        {
            while (q.size() > k)
                q.pop();
            int idx = (q.size() == 0) ? -1 : q.front();
            if (idx >= 0)
            {
                int temp = (idx > 0) ? pre[idx - 1] : 0;
                ans = max(ans, i - q.front() + 1 + temp);
            }
            else
            {
                ans = max(ans, pre[i]);
            }
        }
        else if (k > 0)
        {
            while (q.size() > max(0ll, k - 1))
                q.pop();
            int idx = (q.size() == 0) ? -1 : q.front();
            if (idx >= 0)
            {
                int temp = (idx > 0) ? pre[idx - 1] : 0;
                ans = max(ans, i - q.front() + 1 + temp);
            }
            else
            {
                int cur = 1;
                if (i - 1 >= 0)
                    cur += pre[i - 1];
                ans = max(ans, cur);
            }
            q.push(i);
        }
    }
    cout << ans << endl;
}
int32_t main()
{
    FastIO;

    // w(T)
    {
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //