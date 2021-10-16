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

void solve()
{
    int n, d, c, m;
    cin >> n >> d >> c >> m;
    string s;
    cin >> s;

    bool ans = true;
    int i;
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'D')
        {
            if (d == 0)
            {
                ans = false;
                break;
            }
            d--;
            c += m;
        }
        else
        {
            if (c == 0)
                break;
            c--;
        }
    }
    int dog = 0;
    while (i < n)
        dog += s[i++] == 'D';

    ans &= dog == 0;

    if (ans)
        cout << "YES";
    else
        cout << "NO";

    cout << endl;
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