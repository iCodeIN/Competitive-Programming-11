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
bool ok(v<int> &A, v<bool> &choosen)
{
    int n = A.size();

    v<bool> dp(n + 2, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++)
    {
        if (choosen[i])
        {

            for (int j = 0; j <= n; j++)
            {
                if (dp[j])
                {
                    int x = i ^ j;
                    if (x >= 1 and x <= n)
                        dp[x] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
        if (dp[i] == false)
            return false;
    return true;
}

int solve(v<int> &A, int n, v<bool> &choosen)
{

    if (n == 0)
    {
        if (ok(A, choosen))
        {
            int ans = 0;
            for (int i = 1; i <= A.size(); i++)
                if (choosen[i])
                    ans += A[i - 1];
            return ans;
        }
        return INT_MAX;
    }

    int ans1 = solve(A, n - 1, choosen);
    choosen[n] = true;
    ans1 = min(ans1, solve(A, n - 1, choosen));
    choosen[n] = false;
    return ans1;
}
int mn;

int solve(v<int> &A, int n, v<bool> &choosen, bool secnd)
{

    if (n == 0)
    {
        if (ok(A, choosen))
        {
            int ans = 0;
            for (int i = 1; i <= A.size(); i++)
                if (choosen[i])
                    ans += A[i - 1];
            if (ans == mn)
            {
                for (int i = 1; i <= A.size(); i++)
                    if (choosen[i])
                        cout << i << " ";
            }
            return ans;
        }
        return INT_MAX;
    }

    int ans1 = solve(A, n - 1, choosen, true);
    choosen[n] = true;
    ans1 = min(ans1, solve(A, n - 1, choosen, true));
    choosen[n] = false;
    return ans1;
}

void solve()
{
    int n;
    cin >> n;
    n = 1 << n;
    n--;
    v<int> A(n);

    for (int i = 0; i < n; i++)
        cin >> A[i];

    v<bool> choosen(n + 1);
    int ans = solve(A, n, choosen);
    mn = ans;
    solve(A, n, choosen, true);
    // cout << ans << endl;
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