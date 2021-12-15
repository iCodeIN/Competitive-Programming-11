// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
/* author : pasricha_dhruv */
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#include <bits/stdc++.h>
using namespace std;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#define v(Type) vector<Type>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define ff first
#define ss second
#define int long long
#define mod 1000000007ll
#define endl "\n"
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int solve(v(int) & A, int n, int k)
{
    int ans = 0;
    for (int i = 0; i < n - 2 * k; i++)
        ans += A[i];

    map<int, int> mp;
    for (int i = n - 2 * k; i < n; i++)
        mp[A[i]]++;
    priority_queue<pair<int, int>> pq;
    for (auto itr : mp)
        pq.push({itr.second, itr.first});
    while (pq.size() > 0)
    {
        auto f = pq.top();
        pq.pop();
        if (pq.size() > 0)
        {
            auto s = pq.top();
            pq.pop();
            s.first--;
            f.first--;
            if (s.first)
                pq.push({s.first, s.second});
            if (f.first)
                pq.push({f.first, f.second});
        }
        else if (f.first > 1)
        {
            ans++;
            f.first -= 2;
            if (f.first)
                pq.push({f.first, f.second});
        }
        else
        {
            ans += f.second;
        }
    }
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    v(int) A(n);
    for (int &x : A)
        cin >> x;
    sort(all(A));
    int ans = solve(A, n, k);
    cout << ans << endl;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
