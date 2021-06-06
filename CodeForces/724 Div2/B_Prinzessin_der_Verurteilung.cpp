

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
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

vector<set<string>> possibleAns(4);

void add(int length, string &x)
{
    if (length == 0)
    {
        possibleAns[x.length()].insert(x);
        return;
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        x.push_back(ch);
        add(length - 1, x);
        x.pop_back();
    }
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<string> allSubstrings;
    for (int i = 0; i < n; i++)
        for (int len = 1; len <= n; len++)
            allSubstrings.insert(s.substr(i, len));

    for (auto vc : possibleAns)
    {
        for (auto x : vc)
        {
            if (allSubstrings.find(x) == allSubstrings.end())
            {
                cout << x << endl;
                return;
            }
        }
    }
}

int32_t main()
{
    FastIO;

    int len = 1;
    string temp = "";

    while (len < 4)
    {
        add(len, temp);
        len++;
    }

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
