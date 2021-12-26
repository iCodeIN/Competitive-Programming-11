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
bool exists(uint_fast64_t l, uint_fast64_t r, uint_fast64_t a, uint_fast64_t b)
{
    uint_fast64_t mn = a;
    uint_fast64_t n = b - a + 1;
    uint_fast64_t mx = (n % 2 == 0) ? (n / 2) * (a + b) : n * ((a + b) / 2);
    // cout << mn << " " << mx << endl;
    // return mn <= l and r <= mx;
    if (r < mn or l > mx)
        return false;
    return true;
}
void solve()
{
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    v<pii> A(n);
    int ans = 0;

    for (int i = 0; i < n; i++)
        cin >> A[i].ff >> A[i].ss;

    map<int, int> mp;

    for (auto &p : A)
    {
        mp[p.ff]++;
        mp[p.ss + 1]--;
    }

    int prev = 0;

    for (auto &itr : mp)
    {
        itr.second += prev;
        prev = itr.second;
    }

    auto itr = mp.begin();
    auto next = itr;

    while (itr != mp.end())
    {
        next = itr;
        next++;
        if (next == mp.end())
            break;
        int l = itr->first;
        int r = next->first - 1;
        if (exists(l, r, a, b))
            ans = max(ans, itr->second);
        // cout << l << " " << r << ": " << itr->second << endl;
        itr++;
    }

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
