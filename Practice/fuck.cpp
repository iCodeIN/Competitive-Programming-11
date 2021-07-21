#include <bits/stdc++.h>
using namespace std;

#define int long long int

struct interval
{
    int l;
    int r;
    int k;
};

int solve(vector<interval> &A, int pos, int p, vector<vector<int>> &dp)
{
    int n = A.size();

    if (pos == n or p == 0)
        return 0;

    if (dp[pos][p] != -1)
        return dp[pos][p];

    int ans1 = solve(A, pos + 1, p, dp);

    int i = pos;
    while (i < n)
    {
        if (A[i].l - A[pos].r > 0)
            break;
        i++;
    }
    int ans2 = solve(A, i, p - 1, dp) + A[pos].k;

    return dp[pos][p] = max(ans1, ans2);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int p;
    cin >> p;

    vector<interval> A(n);
    for (auto &x : A)
        cin >> x.l >> x.r >> x.k;

    sort(A.begin(), A.end(), [](const interval &a, const interval &b)
         {
             if (a.l != b.l)
                 return a.r < b.r;
             return a.l < b.l;
         });
    vector<vector<int>> dp(n + 1, vector<int>(p + 1, -1));

    int ans = solve(A, 0, p, dp);

    cout << ans << "\n";
}
