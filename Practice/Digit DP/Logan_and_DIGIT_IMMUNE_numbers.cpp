

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
// #include <reset>
// #include <queue>
// #include <stack>
// #include <unordered_map>
// #include <unordered_reset>
// #include <vector>

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

#define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// _ _ _ _
// 9 7 5 3

int dp[20][2][9][7][16][2];

int solve(string &s, int pos, bool tight, int mod9, int mod7, int used, bool lead)
{

    if (pos == s.length())
    {
        bool three = (used & 1) ? mod9 % 3 != 0 : true;
        bool five = true; // never placed 5 at last
        bool nine = (used & 8) ? mod9 != 0 : true;
        bool seven = (used & 4) ? mod7 != 0 : true;
        // cout << num << "->" << (three and five and nine and seven) << endl;
        return three and five and nine and seven;
    }

    int &ans = dp[pos][tight][mod9][mod7][used][lead];
    if (ans != -1)
        return ans;

    ans = 0;
    if (lead)
    {
        ans += solve(s, pos + 1, false, 0, 0, 0, true);
    }

    int digits[4] = {3, 5, 7, 9};

    int end = (tight) ? s[pos] - '0' : 9;
    int i = 0;
    while (i < 4 and digits[i] < end)
    {
        int mask = (1ll << i);
        if (pos + 1 == s.length() and digits[i] == 5)
        {
        }
        else
        {
            ans += solve(s, pos + 1, false, (mod9 * 10 + digits[i]) % 9, (mod7 * 10 + digits[i]) % 7, used | mask, false);
        }
        i++;
    }

    if (digits[i] <= end)
    {
        int mask = (1ll << i);
        if (pos + 1 == s.length() and digits[i] == 5)
        {
        }
        else
        {
            ans += solve(s, pos + 1, tight, (mod9 * 10 + digits[i]) % 9, (mod7 * 10 + digits[i]) % 7, used | mask, false);
        }
    }

    return ans;
}

void reset(int n)
{
    // 7, 16, 2
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 9; k++)
            {
                for (int l = 0; l < 7; l++)
                {
                    for (int m = 0; m < 16; m++)
                    {
                        dp[i][j][k][l][m][0] = dp[i][j][k][l][m][1] = -1;
                    }
                }
            }
        }
    }
}

void solve()
{
    int l, r, k;
    cin >> l >> r >> k;

    string l_ = to_string(l - 1);
    string r_ = to_string(r);

    // 0....l_
    reset(l_.length());
    int ans1 = solve(l_, 0, true, 0, 0, 0000, true);
    reset(r_.length());
    int ans2 = solve(r_, 0, true, 0, 0, 0000, true);
    // cout << ans1 << " " << ans2 << endl;
    // we want (ans1 + k)th number
    // int k_ = ans1 + k;
    // if(ans1 + k) > ans2 => -1
    if (ans1 > ans2 - k)
    {
        cout << -1 << endl;
        return;
    }
    // else binarySearch on answer
    else
    {
        int low = l - 1;
        int high = r + 1;

        // cout << "searching starts" << endl;
        while (high - low > 1ll)
        {
            int m = ((high - low) >> 1ll) + low;

            string m_ = to_string(m);
            reset(m_.length());
            int ans = solve(m_, 0, true, 0, 0, 0000, true);
            if (ans - k >= ans1)
                high = m;
            else
                low = m;
            // cout << m << "->" << ans << endl;
        }

        cout << high << endl;
    }
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// 10 11 12 13 ................. 100

// leftMost number having ans == k_

// 37 53 57 ..........
