

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
bool check(string &s)
{
    int n = s.length();
    for (int i = 1; i < n; i++)
        if (s[i] == s[i - 1])
            return false;
    return true;
}
void solve()
{
    string s;
    cin >> s;

    int x;
    cin >> x;

    int i = 0;
    sort(all(s));
    bool ans = false;
    do
    {
        if (check(s))
        {
            ++i;
            if (i == x)
            {
                ans = true;
                break;
            }
        }
    } while (next_permutation(all(s)));

    if (ans)
        cout << s << endl;
    else
        cout << -1 << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //