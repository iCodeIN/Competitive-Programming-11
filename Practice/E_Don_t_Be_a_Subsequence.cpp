

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

// #define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

int find(vector<int> &A, int x)
{
    // rightmost value <= x

    int l = -1;
    int r = A.size();

    while (r - l > 1)
    {
        int m = (l + r) >> 1;

        if (A[m] < x)
            l = m;
        else
            r = m;
    }

    return l == -1 ? -1 : A[l];
}

const int N = 2 * 1e5 + 10;
int dp[N + 1][27];

int solve(vector<int> A[], int n)
{

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= 26; j++)
        {
            if (i == 0)
                dp[i][j] = 1;
            else
            {
                int ans = INT32_MAX;

                for (int k = 0; k < 26; k++)
                {
                    int idx = find(A[k], i);

                    int curAns = (idx == -1) ? 0 : dp[idx][k];

                    ans = min(ans, curAns + 1);
                }
                dp[i][j] = ans;
            }
        }
    }
}

void solve()
{
    string s;
    cin >> s;
    reverse(all(s));
    vector<int> A[26];

    for (int i = 0; i < s.length(); i++)
        A[s[i] - 'a'].push_back(i);

    solve(A, s.length());

    int n = s.length();

    int len = dp[n][26];

    string ans = "";
    int p = 26;
    while (len--)
    {

        for (int i = 0; i < 26; i++)
        {
            int idx = find(A[i], n);

            if (idx == -1)
                ans += ('a' + i);
            else if (dp[idx][i] + 1 == dp[n][p])
                ans += ('a' + i), p = i, n = idx;
            else
                continue;

            break;
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //