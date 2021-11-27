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
    int n;
    cin >> n;
    int v;
    cin >> v;

    v(int) A(n);
    for (int &x : A)
        cin >> x;
    queue<int> q;
    int cur = v;
    int start = -1;
    int end = -1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (cur + A[i] >= 0)
        {
            cur += A[i];
            q.push(i);
            if (q.size() > ans)
            {
                start = q.front();
                end = q.back();
                ans = q.size();
            }
        }
        else
        {
            while (q.size() > 0 and cur + A[i] < 0)
            {
                cur -= A[q.front()];
                q.pop();
            }
            if (cur + A[i] >= 0)
            {
                q.push(i);
                cur += A[i];
                if (q.size() > ans)
                {
                    start = q.front();
                    end = q.back();
                    ans = q.size();
                }
            }
        }
    }
    if (start == -1)
        cout << -1;
    else
        cout << start + 1 << " " << end + 1;

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