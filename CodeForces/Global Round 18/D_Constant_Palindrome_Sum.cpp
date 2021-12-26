
// sum = 13

// 2......13

// {1, 3}
// {1, 4}
// {6, 6}
// {6, 7}

// 9
// 1,8

// if(f > sum - 1) dono change
// else 1 change
// same wale sum wale to - krne hi h

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

    v<int> A(n);
    int ans = 0;

    for (int i = 0; i < n; i++)
        cin >> A[i];

    v<pii> P(n);
    map<int, int> mp;
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        P[i].ff = min(A[i], A[j]), P[i].ss = max(A[i], A[j]);
        mp[A[i] + A[j]]++;
    }
    sort(all(P));

    for (int sum = 2; sum <= 2 * k - 1; sum++)
    {
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
