// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
/* author : pasricha_dhruv */
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#include <algorithm>
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

int f(int n, int idx, int s)
{
    return n * idx - s - (n * (n + 1)) / 2;
}

int g(int n, int idx, int s)
{
    return n * idx - s - (n * (n - 1)) / 2;
}

void solve()
{
    string s;
    cin >> s;

    int k;
    cin >> k;

    queue<int> q;
    int sum = 0;
    int ans = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'Y')
        {

            while (q.size() > 0 and f(q.size(), i, sum) > k)
            {
                sum -= q.front();
                q.pop();
            }

            ans = max(ans, (int)q.size() + 1);
            q.push(i);
            sum += i;
        }
        else if (k > 0)
        {
            while (q.size() > 0 and g(q.size(), i, sum) > k)
            {
                sum -= q.front();
                q.pop();
            }
            ans = max(ans, (int)q.size());
        }
        cout << q.size() << " ";
    }
    cout << endl;
    reverse(all(s));
    while (q.size() > 0)
        q.pop();
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'Y')
        {

            while (q.size() > 0 and f(q.size(), i, sum) > k)
            {
                sum -= q.front();
                q.pop();
            }

            ans = max(ans, (int)q.size() + 1);
            q.push(i);
            sum += i;
        }
        else if (k > 0)
        {
            while (q.size() > 0 and g(q.size(), i, sum) > k)
            {
                sum -= q.front();
                q.pop();
            }
            ans = max(ans, (int)q.size());
        }
        cout << q.size() << " ";
    }

    cout << endl;
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