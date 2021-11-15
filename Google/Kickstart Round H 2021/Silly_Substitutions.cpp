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

bool f(string &s, string &x)
{

    bool f = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s.substr(i, 2) == x)
        {
            s.erase(i + 1, 1);
            s[i] = (((x[1] - '0') + 1) % 10 + '0');
            f = true;
        }
    }
    return f;
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int count = 0;
    for (int i = 0;; i++)
    {
        i = i % 10;
        char ch1 = i + '0';
        char ch2 = (i + 1) % 10 + '0';

        string x = "";
        x += ch1;
        x += ch2;

        if (f(s, x))
            count = 0;
        else
            count++;

        if (count == 10)
            break;
    }
    cout << s << endl;
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