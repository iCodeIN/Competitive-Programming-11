

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
#include <bits/stdc++.h>
// #include <cmath>
// #include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>
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

#define v(Type) vector<Type>
#define all(x) x.begin(), x.end()

#define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

const int N = 1e6 + 1;

int dp[N + 1][5];
map<char, int> mp;
map<int, char> mp1;

string Ans = "";

int find(string &s, char x, int j)
{

    while (j >= 0)
    {
        if (s[j] == x)
            return j;
        j--;
    }

    return j;
}

int solve(string &s, int n, int prev)
{

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= 4; j++)
        {
            if (i == 0)
                dp[i][j] = 1;
            else
            {
                int ans = INT32_MAX;

                for (int k = 0; k < 4; k++)
                {
                    int idx = find(s, mp1[k], i - 1);
                    int currentAns = (idx == -1) ? 0 : dp[idx][k];

                    ans = min(currentAns + 1, ans);
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

    mp['A'] = 0;
    mp['C'] = 1;
    mp['G'] = 2;
    mp['T'] = 3;
    mp['-'] = 4;

    mp1[0] = 'A';
    mp1[1] = 'C';
    mp1[2] = 'G';
    mp1[3] = 'T';
    mp1[4] = '-';


    solve(s, s.length(), 4);

    int n = s.length();
    int len = dp[n][4];
    int p = 4;

    while (len--)
    {
        for (int i = 0; i < 4; i++)
        {
            int idx = find(s, mp1[i], n - 1);

            if (idx == -1)
                Ans += mp1[i];
            else if (dp[idx][i] + 1 == dp[n][p])
                Ans += mp1[i], p = i, n = idx;
            else
                continue;

            break;
        }
    }

    reverse(all(Ans));

    cout << Ans << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //