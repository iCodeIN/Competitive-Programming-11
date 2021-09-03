

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
#define d(x) cout << #x << " " << x << endl;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

string f(int a, int b, char ch1, char ch2)
{
    string s = "";
    while (a > 0 or b > 0)
    {
        if (a > 0)
            s += ch1;
        if (b > 0)
            s += ch2;
        a--;
        b--;
    }
    return s;
}

void f(string &s, v(bool) & possible, char ch1, char ch2)
{

    int c = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 == 1 and s[i] != ch2)
            c++;

        if (i % 2 == 0 and s[i] != ch1)
            c++;
    }
    // d(c);
    int pairs = 0;
    for (int i = 1; i < s.size(); i += 2)
    {
        if (s[i] == ch2 and s[i - 1] == ch1)
            pairs++;
    }

    // d(pairs);
    for (int j = 0; j <= pairs; j++)
    {
        possible[c + 2 * j] = true;
    }
    // for (int i = 0; i < possible.size(); i++)
    //     if (possible[i])
    //         cout << i << " ";
    // cout << endl;
}

void solve()
{
    int a, b;
    cin >> a >> b;

    v(bool) possible(a + b + 1, false);

    string x = f(a, b, 'A', 'B');
    string y = f(b, a, 'B', 'A');

    // d(x);
    // d(y);

    f(x, possible, 'A', 'B');
    f(y, possible, 'B', 'A');

    int ans = 0;
    for (int i = 0; i < a + b + 1; i++)
        if (possible[i])
            ans++;

    cout << ans << endl;

    for (int i = 0; i < a + b + 1; i++)
        if (possible[i])
            cout << i << " ";

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