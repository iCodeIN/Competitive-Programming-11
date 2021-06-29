

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>
#include <vector>

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

using namespace std;

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#define w(T)  \
    int T;    \
    cin >> T; \
    while (T--)

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define v(Type) vector<Type>
#define all(x) x.begin(), x.end()

#define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

int dp[101][901];
bool f(int pos, int n, int sum, string &ans)
{
    if ((n - pos) * 9 < sum)
        return dp[pos][sum] = false;

    if (sum < 0)
        return false;
    if (pos == n)
    {
        return sum == 0;
    }

    if (sum == 0)
    {
        while (pos < n)
        {
            ans += '0';
            pos++;
        }
        return dp[pos][sum] = true;
    }

    if (dp[pos][sum] != -1)
        return dp[pos][sum];

    int lb = 1;
    int ub = 9;
    if (pos > 0)
        lb = 0;
    while (lb <= ub)
    {
        char ch = lb + '0';
        ans += ch;
        bool ans_ = f(pos + 1, n, sum - lb, ans);
        if (ans_)
            return dp[pos][sum] = true;
        ans.pop_back();
        lb++;
    }
    return dp[pos][sum] = false;
}
bool g(int pos, int n, int sum, string &ans)
{
    if ((n - pos) * 9 < sum)
        return dp[pos][sum] = false;

    if (sum < 0)
        return false;
    if (pos == n)
    {
        return sum == 0;
    }

    if (sum == 0)
    {
        while (pos < n)
        {
            ans += '0';
            pos++;
        }
        return dp[pos][sum] = true;
    }

    if (dp[pos][sum] != -1)
        return dp[pos][sum];

    int lb = 1;
    int ub = 9;
    if (pos > 0)
        lb = 0;
    while (ub >= lb)
    {
        char ch = ub + '0';
        ans.push_back(ch);
        bool ans_ = g(pos + 1, n, sum - ub, ans);
        if (ans_)
            return dp[pos][sum] = true;
        ans.pop_back();
        ub--;
    }
    return dp[pos][sum] = false;
}

// 6000000000 5099999999

string f(string &a, string &b)
{
    int p1 = a.length() - 1;
    int p2 = b.length() - 1;
    string ans = "";
    while (p2 >= 0 and p1 >= 0)
    {
        int d1 = a[p1];
        int d2 = b[p2];

        if (d2 > d1)
        {
            int p = p1 - 1;

            while (p >= 0 and a[p] == '0')
            {
                a[p] = '9';
                p--;
            }
            if (p >= 0)
                a[p]--;
            d1 += 10;
        }
        char ch = (d1 - d2) + '0';
        // cout << ch << ' ';
        ans += ch;
        p1--;
        p2--;
    }
    while (ans.length() > 0 and ans.back() == '0')
        ans.pop_back();
    reverse(ans.begin(), ans.end());
    if (ans.length() == 0)
        ans += '0';
    // cout << ans << endl;
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    int sum;
    cin >> sum;

    if (sum > 9 * n)
    {
        cout << "NO";
    }
    else
    {
        string minNo = "";
        string maxNo = "";
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= sum; j++)
                dp[i][j] = -1;
        f(0, n, sum, minNo);
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= sum; j++)
                dp[i][j] = -1;
        g(0, n, sum, maxNo);
        // cout << maxNo << " " << minNo << endl;
        string ans = f(maxNo, minNo);

        cout << ans;
    }
    cout << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //