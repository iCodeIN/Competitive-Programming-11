

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

void solve(string &s, int pos, bool tight, string nsf)
{
    if(pos == s.length())
    {
        cout << nsf << endl;
        return;
    }
    int start = 0;
    int end = (tight) ? s[pos] - '0' : 9;

    for (int i = start; i < end; i++)
    {
        solve(s, pos + 1, false, nsf + to_string(i));
    }

    solve(s, pos + 1, tight, nsf + to_string(end));
}

int32_t main()
{
    FastIO;

    int n;
    cin >> n;

    string r = to_string(n);
    solve(r, 0, true, "");

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //