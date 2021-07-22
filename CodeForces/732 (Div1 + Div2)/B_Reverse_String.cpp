

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

bool check(string &s, string &t, int pos1, int pos2)
{

    if (pos2 == (int)t.length())
        return true;

    if (s[pos1] != t[pos2])
    {
        int i = pos1 - 2;
        int j = pos2;

        while (i >= 0 and j < (int)t.length())
            if (s[i--] != t[j++])
                return false;

        return j == (int)(t.length());
    }

    bool ans = check(s, t, pos1 + 1, pos2 + 1);

    return ans;
}

void solve()
{
    string s;
    cin >> s;

    string t;
    cin >> t;

    int n = s.length();
    int m = t.length();
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        ans = check(s, t, i, 0);

        if (ans)
            break;
    }
    if (ans)
        cout << "YES";
    else
        cout << "NO";

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