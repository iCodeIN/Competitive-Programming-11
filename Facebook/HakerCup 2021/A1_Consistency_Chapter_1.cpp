

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

bool isVowel(char ch)
{
    return ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U';
}

int f(string &s, char ch)
{
    int ans = 0;
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (s[i] != ch)
        {
            int a = isVowel(ch);
            int b = isVowel(s[i]);
            ans += 1 + (a == b);
        }
    }
    return ans;
}

void solve()
{
    string s;
    cin >> s;
    int ans = INT64_MAX;
    for (char ch = 'A'; ch <= 'Z'; ch++)
        ans = min(ans, f(s, ch));

    cout << ans << endl;
}

int32_t main()
{
    FastIO;
    int t = 0;
    w(T)
    {
        cout << "Case #" << ++t << ": ";
        solve();
    }
    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //