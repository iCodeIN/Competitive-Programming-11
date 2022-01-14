// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
/* author : pasricha_dhruv */
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#include <iostream>
#include <vector>
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
    v<int> B(n);
    int ans = 0;

    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < n; i++)
        cin >> B[i];

    int pre[n];
    int suf[n];

    pre[0] = A[0] * B[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + A[i] * B[i];
    suf[n - 1] = A[n - 1] * B[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suf[i] = suf[i + 1] + A[i] * B[i];

    for (int c = 0; c < n; c++)
    {
        int l = c;
        int r = c;
        int cur = 0;
        while (l >= 0 and r < n)
        {
            // cout << l << " " << r << endl;
            if (l != r)
                cur += A[l] * B[r] + A[r] * B[l];
            else
                cur += A[l] * B[l];
            int curAns = cur;
            if (l >= 1)
                curAns += pre[l - 1];
            if (r + 1 < n)
                curAns += suf[r + 1];
            ans = max(ans, curAns);
            l--;
            r++;
        }

        l = c;
        r = c + 1;
        cur = 0;
        while (l >= 0 and r < n)
        {
            // cout << l << " " << r << endl;
            cur += (A[l] * B[r]) + (A[r] * B[l]);
            int curAns = cur;
            if (l >= 1)
                curAns += pre[l - 1];
            if (r + 1 < n)
                curAns += suf[r + 1];
            ans = max(ans, curAns);
            l--;
            r++;
        }
    }

    cout << ans << endl;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //