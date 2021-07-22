

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
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

int solve(string &s, int pos, int A, int B, int r1, int r2)
{
    if ((r2 == 0 and r1 == 0) or (A + r1 < B) or (B + r2 < A))
    {
        return 0;
    }

    if (pos & 1)
    {
        if (s[pos] != '?')
            return 1 + solve(s, pos + 1, A, B + (s[pos] == '1'), r1, r2 - 1);

        int ans1 = 1 + solve(s, pos + 1, A, B + 1, r1, r2 - 1);
        int ans2 = 1 + solve(s, pos + 1, A, B, r1, r2 - 1);
        return min(ans1, ans2);
    }
    else
    {
        if (s[pos] != '?')
            return 1 + solve(s, pos + 1, A + (s[pos] == '1'), B, r1 - 1, r2);

        int ans1 = 1 + solve(s, pos + 1, A + 1, B, r1 - 1, r2);
        int ans2 = 1 + solve(s, pos + 1, A, B, r1 - 1, r2);

        return min(ans1, ans2);
    }
}

void solve()
{
    string s;
    cin >> s;

    int ans = solve(s, 0, 0, 0, 5, 5);

    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //