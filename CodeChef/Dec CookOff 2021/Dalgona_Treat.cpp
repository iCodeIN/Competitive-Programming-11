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

void solve(v<int> &A, int n, int sum, set<int> &s, int count = 0)
{
    if (sum < 0)
        return;
    if (n == 0)
    {
        if (sum == 0)
            s.insert(count);
        return;
    }
    solve(A, n, sum - A[n - 1], s, count + 1);
    solve(A, n - 1, sum, s, count);
}

void solve()
{
    int n = 10;
    v<int> A(n);
    for (int i = 1; i <= n; i++)
        A[i - 1] = i * i;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << "-> {";
        set<int> st;
        solve(A, n, A[i], st);
        for (auto &itr : st)
            cout << itr << ", ";
        cout << "}" << endl;
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