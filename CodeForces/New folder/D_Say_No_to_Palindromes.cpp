

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
    int a = 0;
    int b = 0;
    int c = 0;
};

int f(v(node) & pre, int l, int r, char ch)
{

    if (l > r)
        return 0;

    while (r % 3 != l % 3)
        r--;

    int req = (r - l) / 3 + 1;
    int present = 0;

    auto r_ = pre[r];
    node l_ = pre[max(0ll, l - 3)];

    if (ch == 'a')
        present = r_.a - l_.a;
    else if (ch == 'b')
        present = r_.b - l_.b;
    else
        present = r_.c - l_.c;

    return req - present;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    v(node) pre(n + 10);

    for (int i = 1; i <= n; i++)
    {
        node temp;
        if (s[i] == 'a')
            temp.a++;
        else if (s[i] == 'b')
            temp.b++;
        else if (s[i] == 'c')
            temp.c++;

        pre[i].a = pre[max(0ll, i - 3)].a + temp.a;

        pre[i].b = pre[max(0ll, i - 3)].b + temp.b;

        pre[i].c = pre[max(0ll, i - 3)].c + temp.c;
    }

    while (q--)
    {

        int l, r;
        cin >> l >> r;
        int ans = r - l + 1;
        int f1, f2, f3;
        //abc
        f1 = f(pre, l, r, 'a');
        f2 = f(pre, l + 1, r, 'b');
        f3 = f(pre, l + 2, r, 'c');
        ans = min(ans, f1 + f2 + f3);
        //acb
        f1 = f(pre, l, r, 'a');
        f2 = f(pre, l + 1, r, 'c');
        f3 = f(pre, l + 2, r, 'b');
        ans = min(ans, f1 + f2 + f3);
        // bac
        f1 = f(pre, l, r, 'b');
        f2 = f(pre, l + 1, r, 'a');
        f3 = f(pre, l + 2, r, 'c');
        ans = min(ans, f1 + f2 + f3);
        //bca
        f1 = f(pre, l, r, 'b');
        f2 = f(pre, l + 1, r, 'c');
        f3 = f(pre, l + 2, r, 'a');
        ans = min(ans, f1 + f2 + f3);
        //cab
        f1 = f(pre, l, r, 'c');
        f2 = f(pre, l + 1, r, 'a');
        f3 = f(pre, l + 2, r, 'b');
        ans = min(ans, f1 + f2 + f3);
        //cba
        f1 = f(pre, l, r, 'c');
        f2 = f(pre, l + 1, r, 'b');
        f3 = f(pre, l + 2, r, 'a');
        ans = min(ans, f1 + f2 + f3);

        cout << ans << endl;
    }
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //