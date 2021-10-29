

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

struct node
{
    int idx;
    int f;
};

char invert(char ch)
{
    if (ch == 'a')
        ch++;
    else
        ch--;
    return ch;
}

void solve()
{
    string s;
    cin >> s;

    int n = s.length();
    v(int) A;
    int i = 0;
    while (i < n)
    {
        int j = i + 1;

        while (j < n and s[j] == s[i])
            j++;
        A.push_back({i, j - i - 1});
        i = j;
    }

    if (A.size() % 2 == 0)
    {
        node last = A.back();
        s[last.idx + last.f] = invert(s[last.idx]);
    }
    cout << s << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //