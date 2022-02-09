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

    int k;
    cin >> k;

    if (n == 4 and k == n - 1)
    {
        cout << -1 << endl;
    }
    else
    {
        bool mx = (k == n - 1);
        if (mx)
            k--;
        int m = n / 2;
        v<pii> A(m);
        int v = 0;
        int idx = -1;
        for (int i = 0; i < m; i++)
        {
            A[i].ff = v++;
            if (A[i].ff == k)
                idx = i;
        }

        for (int i = m - 1; i >= 0; i--)
        {
            A[i].ss = v++;
            if (A[i].ss == k)
                idx = i;
        }

        if (A[idx].ss == k)
            swap(A[idx].ss, A[0].ff);
        else
            swap(A[idx].ff, A[0].ff);

        if (mx)
        {
            swap(A[2].ff, A[3].ff);
        }
        
        for (int i = 0; i < m; i++)
            cout << A[i].ff << " " << A[i].ss << endl;
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