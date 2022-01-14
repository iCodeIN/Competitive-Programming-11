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
// #define int LL
#define ss second
#define v vector
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int dp[1000][1000][2];
bool solve(int ones, int nonOnes, bool can = true)
{
    if (ones == 0 and nonOnes == 0)
        return false;
    // if (dp[ones][nonOnes][can] != -1)
    //     return dp[ones][nonOnes][can];
    bool ans = false;
    if (nonOnes)
    {
        bool ans1 = solve(ones + 1, nonOnes - 1);
        bool ans2 = solve(ones, nonOnes - 1);
        bool ans3 = (can) ? solve(ones, nonOnes, false) : true;
        if (ans1 == false or ans2 == false or ans3 == false)
            ans = true;
    }

    if (ans == false and ones > 0)
    {
        bool ans1 = solve(ones - 1, nonOnes);
        if (ans1 == false)
            ans = true;
    }

    return dp[ones][nonOnes][can] = ans;
}

void solve()
{
    int n;
    cin >> n;

    v<int> A(n);

    int ones = 0;
    int nonOnes = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        if (A[i] == 1)
            ones++;
        else
            nonOnes++;
    }
    memset(dp, -1, sizeof(dp));
    bool ans = solve(ones, nonOnes);
    if (ans)
        cout << "Utkarsh";
    else
        cout << "Ashish";
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
