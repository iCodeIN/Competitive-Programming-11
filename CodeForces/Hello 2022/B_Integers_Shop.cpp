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
int f(v<pair<pii, int>> &A, int l, int r)
{
    if (l == r)
        return A[l].ss;
    return A[l].ss + A[r].ss;
}

void solve()
{
    int n;
    cin >> n;

    v<pair<pii, int>> A(n);

    for (int i = 0; i < n; i++)
        cin >> A[i].ff.ff >> A[i].ff.ss >> A[i].ss;

    int L = 1e9 + 1;
    int R = 0;

    set<int> start, end;
    map<pii, int> mp;

    for (int i = 0; i < n; i++)
    {
        int l = A[i].ff.ff;
        int r = A[i].ff.ss;

        if (l < L)
        {
            L = l;
            start.clear();
            start.insert(i);
        }

        if (r > R)
        {
            R = r;
            end.clear();
            end.insert(i);
        }

        if (l == L)
        {
            auto itr = start.begin();
            if (A[i].ss < A[*itr].ss)
            {
                start.clear();
                start.insert(i);
            }
            else if (A[i].ss == A[*itr].ss)
            {
                start.insert(i);
            }
        }

        if (r == R)
        {
            auto itr = end.begin();
            if (A[i].ss < A[*itr].ss)
            {
                end.clear();
                end.insert(i);
            }
            else if (A[i].ss == A[*itr].ss)
            {
                end.insert(i);
            }
        }
        if (mp.count({l, r}))
            mp[{l, r}] = min(mp[{l, r}], A[i].ss);
        else
            mp[{l, r}] = A[i].ss;
        int ans = f(A, *start.begin(), *end.begin());

        if (mp.count({L, R}))
            ans = min(ans, mp[{L, R}]);
        
        cout << ans << endl;
    }
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