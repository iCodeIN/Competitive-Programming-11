// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
#include <map>
#include <set>
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

int f(string &s, map<int, set<int>> &mp, char ch)
{
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp[s[i]].count(ch) == 0)
            continue;
        ++ans;
        int j = i;
        while (j < n and mp[s[j]].count(ch))
            j++;
        i = j - 1;
    }
    return ans;
}

void solve()
{

    int n;
    cin >> n;
    string s;
    cin >> s;

    map<int, set<int>> mp;

    mp['R'].insert('R');

    mp['B'].insert('B');

    mp['Y'].insert('Y');

    mp['O'].insert('R');
    mp['O'].insert('Y');

    mp['P'].insert('R');
    mp['P'].insert('B');

    mp['G'].insert('Y');
    mp['G'].insert('B');

    mp['A'].insert('R');
    mp['A'].insert('B');
    mp['A'].insert('Y');


    int ans = 0;

    ans += f(s, mp, 'R');
    ans += f(s, mp, 'B');
    ans += f(s, mp, 'Y');
    
    cout << ans << endl;
}

int32_t main()
{
    FastIO;
    int test = 1;
    w(T)
    {
        cout << "Case #" << test++ << ": ";
        solve();
    }
    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //