// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
/* author : pasricha_dhruv */
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#include <bits/stdc++.h>
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
using namespace std;
using LL = long long unsigned int;
using LD = long double;
using vi = vector<LL>;
using pii = pair<LL, LL>;
const LL mod = INT64_MAX;
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
    int n, k, x;
    cin >> n >> k >> x;

    string s;
    cin >> s;

    v<int> A;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            A.push_back(INT64_MAX);
        else
        {
            int j = i;
            int c = 0;
            while (j < n and s[j] == '*')
                c++, j++;
            A.push_back(c * k);
            i = j - 1;
        }
    }
    n = A.size();
    int current = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        
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