

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

string f(string x)
{

    int i = 0;
    while (i < x.length() and x[i] == '0')
        i++;

    x = x.substr(i);

    if (x == "")
        return "0";
    return x;
}

void solve()
{
    int n;
    cin >> n;

    string s1 = "";
    string s2 = "";

    int i = 1;
    while (n != 0)
    {
        if (i & 1)
            s1 += char(n % 10 + '0');
        else
            s2 += char(n % 10 + '0');

        i++;
        n /= 10;
    }

    reverse(all(s1));
    reverse(all(s2));

    s1 = f(s1);
    s2 = f(s2);

    int ans = (stoll(s1) + 1) * (stoll(s2) + 1) - 2;

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