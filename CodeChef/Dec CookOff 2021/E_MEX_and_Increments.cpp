// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
/* author : pasricha_dhruv */
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#include <bits/stdc++.h>
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
using namespace std;
using LL = long long int;
using LD = long double;
using vi = vector<LL>;
using pii = pair<LL, LL>;
const LL mod = 1e9 + 7;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#define all(x) x.begin(), x.end()
#define double LD
#define endl "\n"
#define ff first
#define int LL
#define ss second
#define v vector
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
void solve()
{
    int n;
    cin >> n;

    v<int> A(n);
    int ans = 0;

    for (int i = 0; i < n; i++)
        cin >> A[i];
    sort(all(A));
    map<int, int> mp;
    for (int x : A)
        mp[x]++;
    map<int, int, greater<int>> extra;
    v<int> Ans(n + 2);
    v<int> Pre(n + 2);
    int stopIdx = n;
    for (int i = 0; i <= n; i++)
    {
        Ans[i] = mp[i];

        if (mp[i] == 0)
        {
            if (extra.size() == 0)
            {
                stopIdx = i;
                break;
            }
            else
            {
                int x = extra.begin()->first;
                Pre[i + 1] = i - x;
                extra[x]--;
                if (extra[x] == 0)
                    extra.erase(x);
            }
        }
        if (mp[i] > 1)
            extra[i] = mp[i] - 1;
    }
    for (int i = 1; i <= n; i++)
        Pre[i] += Pre[i - 1];

    for (int i = 0; i <= stopIdx; i++)
        cout << Ans[i] + Pre[i] << " ";

    for (int i = stopIdx + 1; i <= n; i++)
        cout << -1 << " ";

    cout << endl;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
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