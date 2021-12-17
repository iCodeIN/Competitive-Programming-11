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

    map<int, int> mp;
    set<int> done;
    bool ok = true;
    for (int x : A)
    {
        if (x > n or done.count(x))
        {
            mp[x - ((x / 2) + 1)]++;
        }
        else
        {
            done.insert(x);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!done.count(i))
        {
            auto itr = mp.lower_bound(i);
            if (itr == mp.end())
            {
                ok = false;
                break;
            }
            ans++;
            int f = itr->first;
            int s = itr->second;
            s--;
            mp[f] = s;
            if (s == 0)
                mp.erase(f);
        }
    }
    if (!ok)
        ans = -1;
    cout << ans << endl;
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