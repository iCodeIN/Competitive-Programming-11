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
bool testCases = false;
void solve()
{
    int n;
    cin >> n;

    v<int> A(n);
    int ans = 0;

    for (int i = 0; i < n; i++)
        cin >> A[i];
    map<int, int> mp;
    for (int i = n - 1; i >= 0; i--)
    {
        int cur = mp[A[i] + 1] + 1;
        mp[A[i]] = max(mp[A[i]], cur);
        ans = max(ans, cur);
    }
    int v = -1;
    for (int i = 0; i < n; i++)
    {
        if (mp[A[i]] == ans)
        {
            v = A[i];
            break;
        }
    }
    vi Ans(ans);
    int i = 0;
    int idx = 0;
    while (i < n and idx < ans)
    {

        int j = i;
        while (j < n and A[j] != v)
            j++;
        Ans[idx++] = (j + 1);
        i = j + 1;
        v++;
    }
    cout << Ans.size() << endl;
    for (int x : Ans)
        cout << x << " ";
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    if (testCases)
        cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
