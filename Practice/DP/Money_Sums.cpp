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

    v<int> A(n);

    int sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        sum += A[i];
    }

    bool dp[2][sum + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            bool &ans = dp[i % 2][j];
            if (j == 0)
                ans = true;
            else if (i == 0)
                ans = false;
            else
            {
                ans = dp[(i - 1) % 2][j];
                if (!ans and j >= A[i - 1])
                    ans = dp[(i - 1) % 2][j - A[i - 1]];
            }
        }
    }

    v<int> Ans;
    for (int i = 1; i <= sum; i++)
        if (dp[n % 2][i])
            Ans.push_back(i);
    
    cout << Ans.size() << endl;
    for (int x : Ans)
        cout << x << " ";
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