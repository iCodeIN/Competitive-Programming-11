

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

bool check(string &s, int idx, char ch)
{
    while (idx < s.length())
    {
        if (s[idx] == ch)
            return false;

        idx++;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j < n and s[i] == s[j])
            j++;

        ans = check(s, j, s[i]);

        i = j - 1;

        if (ans == false)
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