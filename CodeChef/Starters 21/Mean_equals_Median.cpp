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

bool good(int t, v<int> &A, int sum, int rem)
{
    int n = A.size();
    int operations = n * t + rem;
    int median = (sum + operations) / n;
    int medianIdx = (n + 1) / 2 - 1;
    auto count = upper_bound(A.begin(), A.end(), median) - A.begin();
    // count of elements <= median
    if (count - 1 < medianIdx)
        return false;

    int req = 0;
    int i = count - 1;

    while (i >= medianIdx)
    {
        req += (median - A[i]);
        i--;
    }
    return req <= operations;
}

void solve()
{
    int n;
    cin >> n;

    v<int> A(n);
    int ans = 0;

    for (int i = 0; i < n; i++)
        cin >> A[i];

    sort(all(A));

    int sum = 0;
    for (int x : A)
        sum += x;
    int mx = 0;
    for (int x : A)
        mx += A[n - 1] - x;
    int rem = n - (sum % n);
    rem %= n;

    int l = -1;
    int r = (mx / n) + 100 * n;

    while (r - l > 1)
    {
        int m = (l + r) / 2;

        if (good(m, A, sum, rem))
            r = m;
        else
            l = m;
    }
    ans = n * r + rem;

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