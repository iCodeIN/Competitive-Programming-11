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
class PreCompute
{
public:
    PreCompute()
    {
    }
};
class Solution
{

    void solve()
    {  
        int n;
        cin >> n;

        v<int> A(n);
        int ans = 0;

        for (int i = 0; i < n; i++)
            cin >> A[i];

        cout << ans << endl;
    }

public:
    Solution()
    {
        solve();
    }
};
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    PreCompute preCompute;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        Solution solve;
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //