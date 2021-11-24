

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
#define pii pair<int, int>
#define ff first
#define ss second

bool good(v(pii) & A, int choosen, int rem)
{
    int n = A.size();

    for (int i = 0; i < n; i++)
    {
        if (choosen <= A[i].ff and A[i].ss >= rem - 1)
            choosen++, rem--;
    }

    return rem <= 0;
}

void solve()
{
    int n;
    cin >> n;

    v(pii) A(n);

    for (auto &x : A)
        cin >> x.ff >> x.ss;

    reverse(all(A));
    int l = 0;
    int r = n + 1;

    while (r - l > 1)
    {
        int m = (l + r) >> 1;

        if (good(A, 0, m))
            l = m;
        else
            r = m;
    }
    cout << l << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //