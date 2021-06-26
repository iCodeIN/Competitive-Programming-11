

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
    long double l;
    long double r;
    bool valid;
};

bool check(node &a, node &b)
{
    if (!a.valid or !b.valid)
        return false;

    if (a.l > b.l)
        return check(b, a);

    if (a.r < b.l)
        return false;

    return true;
}

void solve()
{
    int n;
    cin >> n;

    v(node) A(n);

    for (auto &x : A)
    {
        int t;
        cin >> t;

        cin >> x.l >> x.r;

        if (t % 2 == 0)
            x.r -= 0.1;

        if (t > 2)
            x.l += 0.1;

        x.valid = (x.l <= x.r);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans += check(A[i], A[j]);

    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //