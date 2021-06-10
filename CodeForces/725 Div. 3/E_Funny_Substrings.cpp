

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
#include <unordered_map>
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

void operation(string &s, unordered_map<string, string> &mp)
{
    bool found = false;
    int i = 0;
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == ':')
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        int len = i - 1;
        i++;
        while (i < s.length() and (s[i] == '=' or s[i] == ' '))
            i++;
        mp[s.substr(0, len)] = s.substr(i);
    }
    else
    {
        int len = 0;
        i = 0;
        while (s[i] != ' ')
            len++, i++;
        while (s[i] == ' ' or s[i] == '=')
            i++;
        int s1 = i, len1 = 0;
        while (s[i] != ' ')
            len1++, i++;
        while (s[i] == ' ' or s[i] == '+')
            i++;
        int s2 = i, len2 = 0;
        while (s[i] != '\n' and s[i] != 0)
            len2++, i++;
        mp[s.substr(0, len)] = mp[s.substr(s1, len1)] + mp[s.substr(s2, len2)];
    }
}

void solve()
{
    int n;
    cin >> n;

    string s;
    unordered_map<string, string> mp;
    getline(cin, s); // for null character
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        operation(s, mp);
    }
    int i = 0;
    while (s[i] != ' ')
        i++;
    s = mp[s.substr(0, i)];
    int ans = 0;
    for (int i = 0, j = 3; j < s.length(); i++, j++)
        ans += (s.substr(i, 4) == "haha");

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