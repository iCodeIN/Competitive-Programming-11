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
    int mask = 1;

    v<int> A(n);

    while (mask < n)
        mask *= 2;

    if (mask == n)
    {
        A[0] = n - 1;
        A[1] = 0;
        int v = 1;
        int i = n - 1;
        while (i > 1)
            A[i--] = v++;
    }
    else
    {
        mask /= 2;

        A[n - mask] = 0;

        int i = 0;
        int v = n - 1;
        while (i < n - mask)
            A[i++] = v--;

        v = 1;
        i = n - 1;
        while (i > n - mask)
            A[i--] = v++;
    }

    for (int x : A)
        cout << x << " ";
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

// 2 0 1
// 3 2 0 1
// 4 0 3 2 1
// 5 4 0 3 2 1
// 6 5 4 0 3 2 1
// 7 6 5 4 0 3 2 1
// 8 0 7 6 5 4 3 2 1
// 9 8 0 7 6 5 4 3 2 1